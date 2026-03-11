## Translation Work

When performing any translation-related task in this repository (translating strings, adding language support, modifying `.string` directives in `.inc` files, editing `_("...")` macros in C/H files, or working with region map JSON files), you **must** first read and follow the guidelines in `translations/TRANSLATION_GUIDE.md`.

Key points to always respect:

- Do NOT translate placeholders like `{PLAYER}`, `{STR_VAR_1}`, `{B_ATK_NAME_WITH_PREFIX}`, etc.
- Do NOT rename text labels (e.g., `NewBarkTown_Text_Sign:`)
- Preserve control codes (`\n`, `\l`, `\p`) and the `$` string terminator in `.inc` files
- Respect string length limits (`POKEMON_NAME_LENGTH`, `MOVE_NAME_LENGTH`, `ITEM_NAME_LENGTH`, `TYPE_NAME_LENGTH`, etc.)
- Keep lines within ~34-35 characters to fit the GBA text box width
- Use official French Pokemon terminology (names, moves, types, abilities) from Bulbapedia or pokepedia.fr
- Edit JSON source files for map names, not the auto-generated C headers
- For item/move/Pokemon data, always check the relevant `_LENGTH` constant before translating
- For 'you' and 'your' translations, use 'toi' and 'ton' instead of 'tu' and 'ton' when its relevant.
- For '«' and '»' translations, use '“' and '”' instead.
- When you update a file check the `translations/updated_files_<lang>.txt` and add the file to the list if it's not already there. Add also a check for this file in the `translations/TRANSLATION_GUIDE.md`
- if you want to build the game to test changes, run the following command `make -j$(sysctl -n hw.ncpu) -B modern DEBUG=1` in the root of the repository.
