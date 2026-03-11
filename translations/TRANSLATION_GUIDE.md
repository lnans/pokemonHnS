# Translation Guide for Pokemon Heart & Soul

This document describes where all translatable text is located in the Pokemon Heart & Soul codebase and how the text system works. It is intended for anyone wanting to translate the game into French (or any other language).

---

## Table of Contents

1. [Text System Overview](#1-text-system-overview)
2. [Character Encoding (charmap.txt)](#2-character-encoding-charmaptxt)
3. [Map Scripts & NPC Dialogue](#3-map-scripts--npc-dialogue)
4. [System Text Files (data/text/)](#4-system-text-files-datatext)
5. [C-Based UI & System Strings (src/strings.c)](#5-c-based-ui--system-strings-srcstringsc)
6. [Pokemon Data](#6-pokemon-data)
7. [Move Data](#7-move-data)
8. [Item Data](#8-item-data)
9. [Ability Data](#9-ability-data)
10. [Trainer Data](#10-trainer-data)
11. [Region Map & Location Names](#11-region-map--location-names)
12. [Battle Messages](#12-battle-messages)
13. [Easy Chat System](#13-easy-chat-system)
14. [Following Pokemon Messages](#14-following-pokemon-messages)
15. [Options & Menus](#15-options--menus)
16. [Credits](#16-credits)
17. [Miscellaneous Text Sources](#17-miscellaneous-text-sources)
18. [Graphics With Embedded Text](#18-graphics-with-embedded-text)
19. [Important Constraints & Tips](#19-important-constraints--tips)
20. [Recommended Translation Workflow](#20-recommended-translation-workflow)

---

## 1. Text System Overview

Pokemon Heart & Soul is built on the **pokeemerald** decompilation (via Modern Emerald). Text exists in two distinct formats:

### Assembly `.inc` files (GBA script text)

- Located under `data/text/` and `data/maps/*/scripts.inc`
- Use the `.string` directive followed by the text in quotes
- Terminated with `$` (the end-of-string marker)
- Control characters: `\n` (newline), `\l` (scroll line), `\p` (new paragraph/page)

```
NewBarkTown_Text_Sign:
    .string "NEW BARK TOWN\p"
    .string "The Town Where the Winds of\n"
    .string "a New Beginning Blow$"
```

### C source files (`.c` / `.h`)

- Located under `src/` and `src/data/`
- Use the `_("...")` macro, which converts text through the charmap at compile time
- Standard C string concatenation works (adjacent strings are joined)

```c
const u8 gText_MainMenuNewGame[] = _("NEW GAME");
static const u8 sMasterBallDesc[] = _(
    "The best BALL that\n"
    "catches a POKéMON\n"
    "without fail.");
```

### Special placeholders (both formats)

- `{PLAYER}` - Player name
- `{RIVAL}` - Rival name
- `{STR_VAR_1}`, `{STR_VAR_2}`, `{STR_VAR_3}` - Dynamic text variables
- `{B_ATK_NAME_WITH_PREFIX}`, `{B_DEF_NAME_WITH_PREFIX}` - Battle Pokemon names
- `{PKMN}` / `{COLOR ...}` / `{SHADOW ...}` - Formatting tags
- `{KUN}` - Honorific placeholder (empty in English)

**Do not translate placeholders.** They are replaced at runtime.

---

## 2. Character Encoding (charmap.txt)

**File:** `charmap.txt`

This file maps Unicode characters to the GBA's internal byte values. It is critical for translation because it defines which characters the game engine can render.

### Good news for French

The charmap already includes French accented characters:

- `à` (0x16), `á` (0x17), `â` (0x68), `ç` (0x19), `è` (0x1A), `é` (0x1B), `ê` (0x1C), `ë` (0x1D)
- `ì` (0x1E), `î` (0x20), `ï` (0x21), `ò` (0x22), `ó` (0x23), `ô` (0x24)
- `ù` (0x26), `ú` (0x27), `û` (0x28), `ñ` (0x29), `œ` (0x25)
- Uppercase variants: `À` (0x01), `Á` (0x02), `Â` (0x03), `Ç` (0x04), `È` (0x05), `É` (0x06), `Ê` (0x07), `Ë` (0x08), `Œ` (0x10), etc.

**The font already supports French.** No charmap modification is needed for French translation.

If you need characters not in the charmap for other languages, you would need to:

1. Add the character mapping to `charmap.txt`
2. Add the glyph to the font graphics (`src/fonts.c` references the font tile data)

---

## 3. Map Scripts & NPC Dialogue

**Directory:** `data/maps/*/scripts.inc` (~905 files, ~27,675 `.string` lines)

This is the **largest volume of text** in the game. Every map has a `scripts.inc` file containing NPC dialogue, sign text, story events, and scripted scenes.

### Structure

Each map folder (e.g., `data/maps/NewBarkTown/`) contains a `scripts.inc` with:

- Event scripts (movement, flags, conditions)
- Text labels at the bottom of the file, referenced by scripts via `msgbox`

### Example

```
data/maps/NewBarkTown/scripts.inc
```

```asm
NewBarkTown_EventScript_TownSign::
    msgbox NewBarkTown_Text_Sign, MSGBOX_SIGN
    end

@ ... (script code above, text at the bottom) ...

NewBarkTown_Text_Sign:
    .string "NEW BARK TOWN\p"
    .string "The Town Where the Winds of\n"
    .string "a New Beginning Blow$"

NewBarkTown_Text_LassState2:
    .string "Wait, {PLAYER}!\p"
    .string "It's dangerous to go out\n"
    .string "without a POKéMON!\p"
    .string "Wild POKéMON jump out of the grass\n"
    .string "on the way to the next town.$"
```

### What to translate

- Only the content inside `.string "..."` quotes
- Keep the `$` terminator at the end
- Keep `\n`, `\l`, `\p` control codes
- Keep `{PLAYER}`, `{STR_VAR_1}`, etc. placeholders
- Do NOT rename the text labels (e.g., `NewBarkTown_Text_Sign:`)

### Key Johto/Kanto map folders to prioritize

The HnS-specific maps (Johto + Kanto) include cities like:
`NewBarkTown`, `CherrygroveCity`, `VioletCity`, `AzaleaTown`, `GoldenrodCity`, `EcruteakCity`, `OlivineCity`, `CianwoodCity`, `MahoganyTown`, `BlackthornCity`, `PewterCity`, `CeruleanCity`, `VermilionCity`, `CeladonCity`, `SaffronCity`, `FuchsiaCity`, `ViridianCity`, `PalletTown`, and many more.

---

## 4. System Text Files (data/text/)

**Directory:** `data/text/*.inc` (36 files, ~17,625 lines total)

These files contain system-level text in assembly `.string` format, organized by feature:

| File                                        | Content                                                           | Priority |
| ------------------------------------------- | ----------------------------------------------------------------- | -------- |
| `birch_speech.inc`                          | Professor Oak intro speech                                        | HIGH     |
| `trainers.inc`                              | All trainer battle intro/defeat/post-battle text (~2,498 strings) | HIGH     |
| `save.inc`                                  | Save-related messages                                             | HIGH     |
| `obtain_item.inc`                           | Item obtain messages                                              | HIGH     |
| `pkmn_center_nurse.inc`                     | Pokemon Center dialogue                                           | HIGH     |
| `pc.inc`                                    | PC storage messages                                               | HIGH     |
| `pc_transfer.inc`                           | PC transfer messages                                              | HIGH     |
| `mart_clerk.inc`                            | Shop dialogue                                                     | HIGH     |
| `berries.inc`                               | Berry-related text                                                | MEDIUM   |
| `match_call.inc`                            | PokeNav match call dialogue (~2,328 strings)                      | MEDIUM   |
| `tv.inc`                                    | TV show scripts (~2,193 strings)                                  | LOW      |
| `cable_club.inc`                            | Link/multiplayer text                                             | LOW      |
| `contest_strings.inc`                       | Contest text                                                      | LOW      |
| `contest_link.inc`                          | Contest link text                                                 | LOW      |
| `contest_painting.inc`                      | Contest painting descriptions                                     | LOW      |
| `battle_dome.inc`                           | Battle Dome text                                                  | LOW      |
| `battle_tent.inc`                           | Battle Tent text                                                  | LOW      |
| `frontier_brain.inc`                        | Frontier Brain dialogue                                           | LOW      |
| `apprentice.inc`                            | Apprentice text (~1,952 strings)                                  | LOW      |
| `pokedex_rating.inc`                        | Pokedex rating messages                                           | MEDIUM   |
| `lottery_corner.inc`                        | Lottery corner text                                               | LOW      |
| `move_tutors.inc`                           | Move tutor dialogue                                               | MEDIUM   |
| `questionnaire.inc`                         | Questionnaire text                                                | LOW      |
| `mauville_man.inc`                          | Mauville old man stories                                          | LOW      |
| `blend_master.inc`                          | Berry blend text                                                  | LOW      |
| `event_ticket_1.inc` / `event_ticket_2.inc` | Event ticket text                                                 | LOW      |
| `trick_house_mechadolls.inc`                | Trick House text                                                  | LOW      |
| `check_furniture.inc`                       | Furniture descriptions                                            | LOW      |
| `abnormal_weather.inc`                      | Weather event text                                                | LOW      |
| `braille.inc`                               | Braille puzzle text                                               | LOW      |
| `record_mix.inc`                            | Record mixing text                                                | LOW      |
| `pokemon_news.inc`                          | Pokemon news text                                                 | LOW      |
| `shoal_cave.inc`                            | Shoal Cave text                                                   | LOW      |
| `secret_base_trainers.inc`                  | Secret base trainer text                                          | LOW      |
| `surf.inc`                                  | Surfing text                                                      | LOW      |

---

## 5. C-Based UI & System Strings (src/strings.c)

**File:** `src/strings.c` (~2,220 lines)

This is the **central repository for UI strings**. It contains text for:

- Main menu: "NEW GAME", "CONTINUE", "OPTION", "MYSTERY GIFT"
- Start menu: "POKeDEX", "POKeMON", "BAG", "SAVE", etc.
- Player gender selection: "BOY", "GIRL"
- Default player names
- Bag pocket names
- PC box operations
- Berry/item related messages
- Battle Frontier facility names and descriptions
- Status conditions
- Many more system messages

### Example

```c
const u8 gText_MainMenuNewGame[] = _("NEW GAME");
const u8 gText_MainMenuContinue[] = _("CONTINUE");
const u8 gText_TextSpeedSlow[] = _("SLOW");
const u8 gText_TextSpeedMid[] = _("MID");
const u8 gText_TextSpeedFast[] = _("FAST");
```

**Also check:** `include/strings.h` for the extern declarations (useful to find all string names).

---

## 6. Pokemon Data

### Species Names

**File:** `src/data/text/species_names.h` (~464 lines)

```c
[SPECIES_BULBASAUR] = _("BULBASAUR"),
[SPECIES_IVYSAUR] = _("IVYSAUR"),
```

**Note:** Pokemon names have a maximum length defined by `POKEMON_NAME_LENGTH` (typically 10 characters). French official names should fit.

### Pokedex Text (descriptions)

**File:** `src/data/pokemon/pokedex_text.h` (~2,566 lines)

```c
const u8 gBulbasaurPokedexText[] = _(
    "BULBASAUR can be seen napping in bright\n"
    "sunlight. There is a seed on its back.\n"
    "By soaking up the sun's rays, the seed\n"
    "grows progressively larger.");
```

Each entry is 4 lines max. Keep line breaks similar for display.

### Pokedex Category Names

**File:** `src/data/pokemon/pokedex_entries.h` (~5,233 lines)

```c
.categoryName = _("SEED"),
```

These are short category labels like "SEED", "LIZARD", "FIRE", etc.

### Nature Names

**File:** `src/data/text/nature_names.h` (~54 lines)

```c
static const u8 sHardyNatureName[] = _("HARDY");
```

---

## 7. Move Data

### Move Names

**File:** `src/data/text/move_names.h` (~371 lines)

```c
[MOVE_POUND] = _("POUND"),
[MOVE_KARATE_CHOP] = _("KARATE CHOP"),
```

**Note:** Move names have a max length defined by `MOVE_NAME_LENGTH` (typically 12 characters). Some French move names may need abbreviation.

### Move Descriptions

**File:** `src/data/text/move_descriptions.h` (~1,842 lines)

```c
static const u8 sPoundDescription[] = _(
    "Pounds the foe with\n"
    "forelegs or tail.");
```

Usually 2 lines, displayed in the summary screen.

---

## 8. Item Data

### Item Names (inline in items.h)

**File:** `src/data/items.h` (~9,596 lines, ~786 items)

```c
.name = _("MASTER BALL"),
```

**Note:** Item names have a max length (typically 14 characters). Check `ITEM_NAME_LENGTH`.

### Item Descriptions

**File:** `src/data/text/item_descriptions.h` (~1,800 lines)

```c
static const u8 sMasterBallDesc[] = _(
    "The best BALL that\n"
    "catches a POKéMON\n"
    "without fail.");
```

Usually 3 lines.

---

## 9. Ability Data

### Ability Names and Descriptions

**File:** `src/data/text/abilities.h` (~255 lines)

```c
static const u8 sStenchDescription[] = _("Helps repel wild POKéMON.");
```

Short one-line descriptions. Ability names themselves are defined through constants (check `include/constants/abilities.h` for the enum, and the ability name array in the same data file).

---

## 10. Trainer Data

### Trainer Names

**File:** `src/data/trainers.h` (~6,271 lines)

```c
.trainerName = _("SAWYER"),
```

Trainer names are generally proper nouns. You may choose to keep English names or localize them.

### Trainer Class Names

**File:** `src/data/text/trainer_class_names.h` (~85 lines)

```c
[TRAINER_CLASS_HIKER] = _("HIKER"),
[TRAINER_CLASS_BEAUTY] = _("BEAUTY"),
[TRAINER_CLASS_YOUNGSTER] = _("YOUNGSTER"),
```

**Note:** Max 12 characters for class names (see array size `[13]`).

---

## 11. Region Map & Location Names

### Johto/Kanto Map Names (JSON source, auto-generated)

**Files:**

- `src/data/region_map/region_map_sections_johto.json` - Johto map section names
- `src/data/region_map/region_map_sections.json` - Additional map section names

```json
{
  "map_section": "MAPSEC_VIOLET_CITY",
  "name": "VIOLET CITY",
  "x": 12,
  "y": 4,
  "width": 1,
  "height": 1
}
```

Translate the `"name"` field in these JSON files. The build system auto-generates C header files from them.

### Manually defined map names (Johto override)

**File:** `src/data/region_map/region_map_entries_johto.h`
References `sMapName_*` constants. These are generated from the JSON above or defined in `src/region_map.c` (via `#include "data/region_map/region_map_entries.h"`).

### Landmark Names

**File:** `src/landmark.c` (~459 lines)

```c
static const u8 LandmarkName_FlowerShop[] = _("FLOWER SHOP");
static const u8 LandmarkName_PetalburgWoods[] = _("PETALBURG WOODS");
```

These appear on the region map as sub-location labels.

---

## 12. Battle Messages

**File:** `src/battle_message.c` (~3,220 lines)

Contains all in-battle text strings:

```c
static const u8 sText_PkmnGainedEXP[] = _("{B_BUFF1} gained{B_BUFF2}\n{B_BUFF3} EXP. Points!\p");
static const u8 sText_AttackMissed[] = _("{B_ATK_NAME_WITH_PREFIX}'s\nattack missed!");
static const u8 sText_ItDoesntAffect[] = _("It doesn't affect\n{B_DEF_NAME_WITH_PREFIX}…");
static const u8 sText_PlayerGotMoney[] = _("{B_PLAYER_NAME} got ¥{B_BUFF1}\nfor winning!\p");
```

This file also contains:

- Weather messages
- Status condition messages
- Ability activation messages
- Item usage messages
- All move effect messages

### Type Names

**File:** `src/battle_main.c` (around line 795)

```c
const u8 gTypeNames[NUMBER_OF_MON_TYPES][TYPE_NAME_LENGTH + 1] = {
    [TYPE_NORMAL] = _("NORMAL"),
    [TYPE_FIGHTING] = _("FIGHT"),
    ...
    [TYPE_FAIRY] = _("FAIRY"),
};
```

**Note:** Max `TYPE_NAME_LENGTH` characters (typically 6). French type names may need abbreviation (e.g., "COMBAT" for FIGHTING).

---

## 13. Easy Chat System

**Directory:** `src/data/easy_chat/` (~25 files, ~10,929 lines total)

The Easy Chat system (used for mail, greetings, etc.) has categorized word banks:

| File                                                       | Category                      |
| ---------------------------------------------------------- | ----------------------------- |
| `easy_chat_group_greetings.h`                              | Greetings ("HELLO", "THANKS") |
| `easy_chat_group_feelings.h`                               | Feelings words                |
| `easy_chat_group_conditions.h`                             | Condition words               |
| `easy_chat_group_actions.h`                                | Action words                  |
| `easy_chat_group_lifestyle.h`                              | Lifestyle words               |
| `easy_chat_group_hobbies.h`                                | Hobby words                   |
| `easy_chat_group_time.h`                                   | Time-related words            |
| `easy_chat_group_misc.h`                                   | Miscellaneous words           |
| `easy_chat_group_adjectives.h`                             | Adjective words               |
| `easy_chat_group_events.h`                                 | Event words                   |
| `easy_chat_group_move_1.h` / `easy_chat_group_move_2.h`    | Move names                    |
| `easy_chat_group_pokemon.h` / `easy_chat_group_pokemon2.h` | Pokemon names                 |
| `easy_chat_group_trainer.h`                                | Trainer-related words         |
| `easy_chat_group_people.h`                                 | People words                  |
| `easy_chat_group_battle.h`                                 | Battle words                  |
| `easy_chat_group_endings.h`                                | Sentence ending words         |
| `easy_chat_group_speech.h`                                 | Speech words                  |
| `easy_chat_group_status.h`                                 | Status words                  |
| `easy_chat_group_voices.h`                                 | Voice/exclamation words       |
| `easy_chat_group_trendy_saying.h`                          | Trendy sayings                |

```c
const u8 gEasyChatWord_Thanks[] = _("THANKS");
const u8 gEasyChatWord_Hello[] = _("HELLO");
```

---

## 14. Following Pokemon Messages

**File:** `src/data/text/follower_messages.h` (~301 lines)

Messages displayed when you interact with your following Pokemon:

```c
static const u8 sHappyMsg00[] = _("{STR_VAR_1} began poking you in the\nstomach.");
static const u8 sHappyMsg01[] = _("{STR_VAR_1} is happy but shy.");
```

Categories include happy, neutral, sad, weather-dependent, and location-specific messages.

---

## 15. Options & Menus

### Main Options Menu

Strings are in `src/strings.c` (grep for `gText_Option`, `gText_TextSpeed`, `gText_BattleScene`, etc.)

### Options Plus Menu (second page)

**File:** `src/options_plus_menu.c` (~2,125 lines)

```c
static const u8 sText_OptionFastIntro[] = _("FAST INTRO");
static const u8 sText_OptionLargeFollower[] = _("BIG FOLLOWERS");
static const u8 sText_Desc_BattleScene_On[] = _("Show the POKéMON animations\nand attack animations.");
```

Contains both option labels AND their description tooltips.

### Game Setup / Challenge Menu

**File:** `src/tx_rac_menu.c` (~3,301 lines)

```c
static const u8 sText_Gamemode[] = _("GAMEMODE");
static const u8 sText_InfiniteTMs[] = _("REUSABLE TMS");
static const u8 sText_FairyTypes[] = _("ADD FAIRY TYPE");
```

Contains the game setup menus shown at the beginning (difficulty, gamemode, challenges).

### Debug Menu

**File:** `src/debug.c` (~4,990 lines)

```c
static const u8 sDebugText_Utilities[] = _("Utilities…{CLEAR_TO 110}{RIGHT_ARROW}");
static const u8 sDebugText_HealParty[] = _("Heal Party");
```

Lower priority, but good to translate for French developers/testers.

---

## 16. Credits

**File:** `src/data/credits.h` (~994 lines)

```c
static const u8 sCreditsText_PkmnHnS[] = _("POKéMON HEART & SOUL");
static const u8 sCreditsText_LeadDeveloper[] = _("Lead Developer");
static const u8 sCreditsText_Developers[] = _("Developers");
static const u8 sCreditsText_Playtesters[] = _("Playtesters");
```

Translate role titles (e.g., "Lead Developer" -> "Developpeur Principal"). Keep proper names untranslated.

---

## 17. Miscellaneous Text Sources

### Decoration Names & Descriptions

**File:** `src/data/decoration/header.h` (names) and `src/data/decoration/description.h` (descriptions)

```c
.name = _("SMALL DESK"),
```

### Ribbon Descriptions

**File:** `src/data/text/ribbon_descriptions.h` (~48 lines)

```c
const u8 gRibbonDescriptionPart1_Champion[] = _("CHAMPION-beating, HALL");
```

### Gift Ribbon Descriptions

**File:** `src/data/text/gift_ribbon_descriptions.h` (~115 lines)

### Match Call Messages

**File:** `src/data/text/match_call_messages.h` (~471 lines)
PokeNav match call character intros/strategies.

### Berry Data Text

**File:** `data/text/berries.inc` (~157 strings)

### Bard Music Words

**Directory:** `src/data/bard_music/*.h` (24 files)
These relate to the Mauville City bard's song system - they contain phonetic data, not text to translate.

---

## 18. Graphics With Embedded Text

Some game graphics contain baked-in English text as pixel art. These need to be re-drawn for translation:

- **Type icons** in `graphics/types/` - The type name labels (NORMAL, FIRE, etc.) are rendered as pixel graphics, not text. You would need to edit the `.4bpp` tile data or re-export from PNG source if available.
- **Title screen** and logos may contain English text
- **Battle UI elements** may have text baked into tileset graphics
- **Font files** referenced in `src/fonts.c` define the character glyph shapes

For the type icons specifically, the compiled graphics are at:

```
graphics/types/move_types.4bpp.lz
```

Referenced from `src/graphics.c`.

---

## 19. Important Constraints & Tips

### String Length Limits

Many strings have hard-coded maximum lengths:

- **Pokemon names:** `POKEMON_NAME_LENGTH` (10 chars)
- **Move names:** `MOVE_NAME_LENGTH` (12 chars)
- **Item names:** `ITEM_NAME_LENGTH` (14 chars)
- **Type names:** `TYPE_NAME_LENGTH` (6 chars)
- **Trainer class names:** 12 chars
- **Map names:** variable, but limited by UI window width

Check `include/constants/global.h` or similar for these constants. If French names exceed these limits, you may need to increase the constants and adjust UI layouts.

### Text Box Width

The GBA screen is 240 pixels wide. A text box is typically ~224 pixels. With the default font, this fits approximately **34-35 characters** per line. Keep dialogue lines within this width.

### Line Breaks

- `\n` = new line (stays in same text box)
- `\l` = scroll line (scrolls text up by one line)
- `\p` = new paragraph (clears text box, waits for button press)
- Always end strings with `$` in `.inc` files

### Build System

The JSON map name files (`region_map_sections*.json`) are processed by `jsonproc` during build to generate C headers. Edit the JSON, not the generated headers.

### Testing

After translating, rebuild with `make modern` and test in mGBA. Pay attention to:

- Text overflow in menus and dialog boxes
- Truncated names
- Broken line wrapping

---

## 20. Recommended Translation Workflow

### Phase 1: Core Gameplay Text (highest impact)

1. `src/strings.c` - All UI/menu strings
2. `data/text/birch_speech.inc` - Intro speech
3. `data/maps/*/scripts.inc` - NPC dialogue (start with story-critical maps)
4. `data/text/trainers.inc` - Trainer battle text
5. `src/battle_message.c` - Battle system messages
6. `src/data/text/species_names.h` - Pokemon names
7. `src/data/text/move_names.h` - Move names
8. `src/data/items.h` - Item names
9. `data/text/obtain_item.inc` - Item obtain messages
10. `data/text/save.inc` - Save messages
11. `data/text/pkmn_center_nurse.inc` - Pokemon Center
12. `data/text/mart_clerk.inc` - Shop text

### Phase 2: Extended Pokemon Data

1. `src/data/pokemon/pokedex_text.h` - Pokedex descriptions
2. `src/data/pokemon/pokedex_entries.h` - Category names
3. `src/data/text/move_descriptions.h` - Move descriptions
4. `src/data/text/item_descriptions.h` - Item descriptions
5. `src/data/text/abilities.h` - Ability descriptions
6. `src/data/text/nature_names.h` - Nature names
7. `src/data/text/follower_messages.h` - Following Pokemon text

### Phase 3: World & UI

1. `src/data/region_map/region_map_sections_johto.json` - Johto map names
2. `src/data/region_map/region_map_sections.json` - Other map names
3. `src/landmark.c` - Landmark names
4. `src/battle_main.c` - Type names
5. `src/data/text/trainer_class_names.h` - Trainer class names
6. `src/options_plus_menu.c` - Options menu text
7. `src/tx_rac_menu.c` - Game setup menu text
8. `data/text/pokedex_rating.inc` - Pokedex rating

### Phase 4: Side Content

1. `src/data/easy_chat/` - Easy Chat word banks
2. `data/text/match_call.inc` - Match call dialogue
3. `data/text/tv.inc` - TV shows
4. `data/text/contest_strings.inc` - Contest text
5. `src/data/decoration/` - Decoration names/descriptions
6. `src/data/text/ribbon_descriptions.h` - Ribbons
7. `src/data/credits.h` - Credits
8. `data/text/battle_tent.inc` / `battle_dome.inc` / `frontier_brain.inc` - Battle Frontier
9. `data/text/apprentice.inc` - Apprentice text
10. `src/debug.c` - Debug menu (optional)

### Keep the French file list updated

Whenever you translate or modify a file as part of the French translation, add its path to:

- `translations/updated_file_list_fr.txt`

This list is used as a simple tracker of what has been touched for the FR effort.

### Multi-Language Architecture (for future languages)

If you plan to support multiple languages, consider creating a directory structure like:

```
translations/
  fr/
    strings.c
    map_scripts/
      NewBarkTown.inc
      ...
  es/
    ...
```

And using preprocessor conditionals or a build-time script to swap the text files based on the target language. However, the GBA ROM has limited space, so shipping multiple languages in one ROM may require compression or selective inclusion.

A simpler approach for a single translation: create a `fr` branch in git and translate directly in the source files.

---

## 21. Community Practices & Resources for ROM Hack Translation

There is no single "official" community guide for translating pokeemerald-based ROM hacks. However, based on research across the pret ecosystem (pokeemerald wiki, PokeCommunity, romhacking.net, and GitHub), here are the established community practices:

### Why decomp-based translation is much easier than binary hacking

The original way to translate GBA Pokemon games was **binary ROM hacking** -- editing hex values directly in a compiled ROM using tools like ROMs editors, hex editors, and table files. This was extremely tedious:

- Every string had a fixed byte length in the ROM
- Longer translations required relocating pointers
- Tools like `common_text_dumper` or custom scripts were needed to extract/inject text
- One wrong byte could corrupt the entire ROM

With a **decompilation project** like pokeemerald (and Heart & Soul), all text is in human-readable source files. You simply edit the text in `.inc` and `.c`/`.h` files, then recompile. The assembler/compiler handles all pointer calculations automatically. This is a massive advantage.

### Common community approaches

#### Approach 1: Fork & Translate (most common)

The most common method used by the community:

1. **Fork** the repository on GitHub
2. Create a **translation branch** (e.g., `fr-translation`)
3. Translate text files directly in the source code
4. Rebuild with `make modern`
5. Distribute the resulting `.gba` or a `.ups` patch

This is what most fan translation teams do. Examples include Spanish, Portuguese, and Italian translations of various pokeemerald hacks.

#### Approach 2: Script-assisted extraction

Some translators write Python/shell scripts to:

1. **Extract** all translatable strings from source files into a spreadsheet (CSV/JSON)
2. **Translate** in the spreadsheet (easier for non-programmers, allows parallel work)
3. **Inject** translated strings back into source files

This is useful for coordinating a team of translators who may not be comfortable with code.

Example extraction script approach:

```python
# Extract all _("...") strings from C files
import re
pattern = r'_\("([^"]+)"\)'
# Extract all .string "..." from .inc files
pattern_asm = r'\.string "([^"]+)"'
```

#### Approach 3: Diff-based patches

Some translators maintain their translation as a set of git patches or diff files that can be applied on top of the original repo. This makes it easier to keep up with upstream updates.

### Key community resources

| Resource                      | URL                                                | What it offers                                                                                      |
| ----------------------------- | -------------------------------------------------- | --------------------------------------------------------------------------------------------------- |
| **pret/pokeemerald wiki**     | https://github.com/pret/pokeemerald/wiki           | Engine documentation, tutorials, text system info                                                   |
| **pokeemerald Tutorials**     | https://github.com/pret/pokeemerald/wiki/Tutorials | 200+ modding tutorials (none specifically for translation, but useful for understanding the engine) |
| **PokeCommunity ROM Hacking** | https://pokecommunity.com                          | Largest community for ROM hack discussion, translation teams often recruit here                     |
| **romhacking.net**            | https://romhacking.net/translations/               | Repository of completed translations (mostly binary patches, but good reference for terminology)    |
| **Team Aqua's Asset Repo**    | https://github.com/Pawkkie/Team-Aquas-Asset-Repo   | Shared free-to-use assets for pokeemerald hacks                                                     |
| **pret Discord**              | (see pokeemerald README)                           | Active community for technical questions                                                            |
| **Heart & Soul Discord**      | https://discord.gg/KmuvXJrS9M                      | HnS-specific community, best place to coordinate translation efforts                                |

### Using official French Pokemon terminology

When translating, use the official French Pokemon names, move names, type names, etc. from the main series games. Key references:

- **Bulbapedia** has French names for all Pokemon, moves, abilities, items, etc.
- **Pokedex.org** or **pokepedia.fr** (the French Pokemon wiki) are excellent references
- The official French games use specific conventions (e.g., "POKeMON" stays as "POKeMON", type names like "COMBAT" for Fighting, "FEE" for Fairy)

### Tools the community uses

| Tool                         | Purpose                                                      |
| ---------------------------- | ------------------------------------------------------------ |
| **Porymap 5**                | Map editor (HnS is not yet compatible with Porymap 6)        |
| **mGBA**                     | Recommended emulator for testing                             |
| **devkitARM (v65 or older)** | Required compiler toolchain                                  |
| **grep/ripgrep**             | Finding text across the codebase                             |
| **VSCode/Cursor**            | Code editor with good search-and-replace across files        |
| **Git**                      | Version control, essential for managing translation branches |
| **diff/patch**               | For maintaining translation as patches over the original     |

### Lessons learned from community translation projects

1. **Start with a playable build** -- Make sure you can compile and run the game before starting translation. Follow the [INSTALL.md](https://github.com/pret/pokeemerald/blob/master/INSTALL.md) guide.

2. **Translate iteratively** -- Don't try to translate everything at once. Start with the intro, first town, and first route. Play through to make sure nothing is broken, then continue.

3. **Watch for string length limits** -- This is the #1 source of bugs in translations. Many arrays have fixed maximum sizes. If a French name is too long, the game will crash or display garbage. Always check the `_LENGTH` constants.

4. **Test text rendering in-game** -- Some characters may look different than expected. The GBA font is narrow, and accented characters may not render perfectly at all sizes.

5. **Keep the original as comments** -- When translating, consider keeping the original English text as a comment next to the translation. This makes it easier to track what was translated and to update when the original changes.

6. **Use `make modern` only** -- The HnS project requires the modern compiler. The old compiler will not work.

7. **Coordinate with the HnS dev team** -- If you plan to publish your translation, reach out on the Heart & Soul Discord. They may have plans or preferences for how translations are handled.

---

## Summary Statistics

| Category                       | Files     | Approximate String Count |
| ------------------------------ | --------- | ------------------------ |
| Map scripts (NPC dialogue)     | ~905      | ~27,675 strings          |
| System text (data/text/)       | 36        | ~10,500 strings          |
| UI strings (strings.c)         | 1         | ~1,100 strings           |
| Battle messages                | 1         | ~500 strings             |
| Pokemon names                  | 1         | ~460 names               |
| Move names + descriptions      | 2         | ~700 entries             |
| Item names + descriptions      | 2         | ~1,500 entries           |
| Ability descriptions           | 1         | ~130 entries             |
| Trainer data (names + classes) | 2         | ~700 entries             |
| Easy Chat words                | ~25       | ~1,000 words             |
| Pokedex text                   | 2         | ~460 entries             |
| Follower messages              | 1         | ~150 messages            |
| Region map / landmarks         | ~4        | ~150 names               |
| Options/menus/credits          | ~4        | ~200 strings             |
| **TOTAL**                      | **~985+** | **~45,000+ strings**     |

This is a large translation effort. Prioritize the Phase 1 items for a playable French version, then iterate through the remaining phases.
