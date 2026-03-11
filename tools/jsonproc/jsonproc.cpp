// jsonproc.cpp

#include "jsonproc.h"

#include <map>

#include <string>
using std::string; using std::to_string;

#include <algorithm>
using std::replace_if;

#include <inja.hpp>
using namespace inja;
using json = nlohmann::json;

std::map<string, string> customVars;

void set_custom_var(string key, string value)
{
    customVars[key] = value;
}

string get_custom_var(string key)
{
    return customVars[key];
}

// Maps UTF-8 continuation byte (second byte of 0xC3 xx sequence) to ASCII equivalent.
// Returns '\0' if not a known accented character.
static char utf8_c3_to_ascii(unsigned char next)
{
    switch (next)
    {
        case 0x80: case 0x81: case 0x82: return 'A';  // ÀÁÂ
        case 0x88: case 0x89: case 0x8A: case 0x8B: return 'E';  // ÈÉÊË
        case 0x8E: case 0x8F: return 'I';  // ÎÏ
        case 0x92: case 0x93: case 0x94: case 0x96: return 'O';  // ÒÓÔÖ
        case 0x99: case 0x9A: case 0x9B: return 'U';  // ÙÚÛ
        case 0xA0: case 0xA1: case 0xA2: case 0xA4: return 'a';  // àáâä
        case 0xA7: return 'c';  // ç
        case 0xA8: case 0xA9: case 0xAA: case 0xAB: return 'e';  // èéêë
        case 0xAC: case 0xAD: case 0xAE: case 0xAF: return 'i';  // ìíîï
        case 0xB2: case 0xB3: case 0xB4: case 0xB6: return 'o';  // òóôö
        case 0xB9: case 0xBA: case 0xBB: case 0xBC: return 'u';  // ùúûü
        case 0xBF: return 'y';  // ÿ
        default: return '\0';
    }
}

int main(int argc, char *argv[])
{
    if (argc != 4)
        FATAL_ERROR("USAGE: jsonproc <json-filepath> <template-filepath> <output-filepath>\n");

    string jsonfilepath = argv[1];
    string templateFilepath = argv[2];
    string outputFilepath = argv[3];

    Environment env;
    env.set_trim_blocks(true);

    // Add custom command callbacks.
    env.add_callback("doNotModifyHeader", 0, [jsonfilepath, templateFilepath](Arguments& args) {
        return "//\n// DO NOT MODIFY THIS FILE! It is auto-generated from " + jsonfilepath +" and Inja template " + templateFilepath + "\n//\n";
    });

    env.add_callback("subtract", 2, [](Arguments& args) {
        int minuend = args.at(0)->get<int>();
        int subtrahend = args.at(1)->get<int>();

        return minuend - subtrahend;
    });

    env.add_callback("setVar", 2, [=](Arguments& args) {
        string key = args.at(0)->get<string>();
        string value = args.at(1)->get<string>();
        set_custom_var(key, value);
        return "";
    });

    env.add_callback("setVarInt", 2, [=](Arguments& args) {
        string key = args.at(0)->get<string>();
        string value = to_string(args.at(1)->get<int>());
        set_custom_var(key, value);
        return "";
    });

    env.add_callback("getVar", 1, [=](Arguments& args) {
        string key = args.at(0)->get<string>();
        return get_custom_var(key);
    });

    env.add_callback("concat", 2, [](Arguments& args) {
        string first = args.at(0)->get<string>();
        string second = args.at(1)->get<string>();
        return first + second;
    });

    env.add_callback("removePrefix", 2, [](Arguments& args) {
        string rawValue = args.at(0)->get<string>();
        string prefix = args.at(1)->get<string>();
        string::size_type i = rawValue.find(prefix);
        if (i != 0)
            return rawValue;

        return rawValue.erase(0, prefix.length());
    });

    env.add_callback("removeSuffix", 2, [](Arguments& args) {
        string rawValue = args.at(0)->get<string>();
        string suffix = args.at(1)->get<string>();
        string::size_type i = rawValue.rfind(suffix);
        if (i == string::npos)
            return rawValue;

        return rawValue.substr(0, i);
    });

    // single argument is a json object
    env.add_callback("isEmpty", 1, [](Arguments& args) {
        return args.at(0)->empty();
    });

    env.add_callback("isEmptyString", 1, [](Arguments& args) {
        return args.at(0)->get<string>().empty();
    });

    env.add_callback("cleanString", 1, [](Arguments& args) {
        string badChars = ".'{} \n\t-";
        string str = args.at(0)->get<string>();
        for (unsigned int i = 0; i < str.length(); i++) {
            if (badChars.find(str[i]) != std::string::npos) {
                str[i] = '_';
                continue;
            }
            unsigned char c = static_cast<unsigned char>(str[i]);
            if (c == 0xC3 && i + 1 < str.size())
            {
                char ascii = utf8_c3_to_ascii(static_cast<unsigned char>(str[i + 1]));
                if (ascii != '\0')
                {
                    str[i] = ascii;
                    str.erase(i + 1, 1);
                }
            }
        }
        return str;
    });

    try
    {
        env.write_with_json_file(templateFilepath, jsonfilepath, outputFilepath);
    }
    catch (const std::exception& e)
    {
        FATAL_ERROR("JSONPROC_ERROR: %s\n", e.what());
    }

    return 0;
}
