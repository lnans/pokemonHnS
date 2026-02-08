# Translation Progress Tracker - French (FR)

> Companion file to [TRANSLATION_GUIDE.md](./TRANSLATION_GUIDE.md).
> Check off items as they are fully translated. Use `[ ]` (pending), `[~]` (in progress), `[x]` (done).

---

## Phase 1: Core Gameplay Text

| Status | File                              | Description                           | ~Strings |
| ------ | --------------------------------- | ------------------------------------- | -------- |
| [x]    | `src/strings.c`                   | UI & menu strings                     | ~1,100   |
| [ ]    | `data/text/birch_speech.inc`      | Prof. Oak intro speech                | ~30      |
| [ ]    | `data/text/trainers.inc`          | Trainer battle intro/defeat/post text | ~2,498   |
| [ ]    | `src/battle_message.c`            | All in-battle text                    | ~500     |
| [ ]    | `src/data/text/species_names.h`   | Pokemon names                         | ~464     |
| [ ]    | `src/data/text/move_names.h`      | Move names                            | ~371     |
| [ ]    | `src/data/items.h`                | Item names                            | ~786     |
| [ ]    | `data/text/obtain_item.inc`       | Item obtain messages                  | —        |
| [ ]    | `data/text/save.inc`              | Save-related messages                 | —        |
| [ ]    | `data/text/pkmn_center_nurse.inc` | Pokemon Center dialogue               | —        |
| [ ]    | `data/text/pc.inc`                | PC storage messages                   | —        |
| [ ]    | `data/text/pc_transfer.inc`       | PC transfer messages                  | —        |
| [ ]    | `data/text/mart_clerk.inc`        | Shop dialogue                         | —        |

### Map Scripts (NPC Dialogue) — ~27,675 strings across ~905 files

> This is the biggest chunk. Track per-region or per-city as you go.

#### Johto Cities

| Status | Map Folder                   | Notes         |
| ------ | ---------------------------- | ------------- |
| [ ]    | `data/maps/NewBarkTown/`     | Starting town |
| [ ]    | `data/maps/Route29/`         |               |
| [ ]    | `data/maps/CherrygroveCity/` |               |
| [ ]    | `data/maps/Route30/`         |               |
| [ ]    | `data/maps/Route31/`         |               |
| [ ]    | `data/maps/VioletCity/`      |               |
| [ ]    | `data/maps/Route32/`         |               |
| [ ]    | `data/maps/AzaleaTown/`      |               |
| [ ]    | `data/maps/Route33/`         |               |
| [ ]    | `data/maps/Route34/`         |               |
| [ ]    | `data/maps/GoldenrodCity/`   |               |
| [ ]    | `data/maps/Route35/`         |               |
| [ ]    | `data/maps/Route36/`         |               |
| [ ]    | `data/maps/Route37/`         |               |
| [ ]    | `data/maps/EcruteakCity/`    |               |
| [ ]    | `data/maps/Route38/`         |               |
| [ ]    | `data/maps/Route39/`         |               |
| [ ]    | `data/maps/OlivineCity/`     |               |
| [ ]    | `data/maps/Route40/`         |               |
| [ ]    | `data/maps/Route41/`         |               |
| [ ]    | `data/maps/CianwoodCity/`    |               |
| [ ]    | `data/maps/Route42/`         |               |
| [ ]    | `data/maps/MahoganyTown/`    |               |
| [ ]    | `data/maps/Route43/`         |               |
| [ ]    | `data/maps/Route44/`         |               |
| [ ]    | `data/maps/BlackthornCity/`  |               |
| [ ]    | `data/maps/Route45/`         |               |
| [ ]    | `data/maps/Route46/`         |               |

#### Johto Dungeons & Interiors

| Status | Map Folder                 | Notes |
| ------ | -------------------------- | ----- |
| [ ]    | `data/maps/SproutTower*/`  |       |
| [ ]    | `data/maps/SlowpokeWell*/` |       |
| [ ]    | `data/maps/IlexForest/`    |       |
| [ ]    | `data/maps/UnionCave*/`    |       |
| [ ]    | `data/maps/BurnedTower*/`  |       |
| [ ]    | `data/maps/BellTower*/`    |       |
| [ ]    | `data/maps/WhirlIslands*/` |       |
| [ ]    | `data/maps/MtMortar*/`     |       |
| [ ]    | `data/maps/LakeOfRage/`    |       |
| [ ]    | `data/maps/TeamRocketHQ*/` |       |
| [ ]    | `data/maps/IcePath*/`      |       |
| [ ]    | `data/maps/DragonsDen*/`   |       |
| [ ]    | `data/maps/DarkCave*/`     |       |
| [ ]    | `data/maps/TohjoFalls/`    |       |

#### Kanto Cities

| Status | Map Folder                  | Notes |
| ------ | --------------------------- | ----- |
| [ ]    | `data/maps/PalletTown/`     |       |
| [ ]    | `data/maps/ViridianCity/`   |       |
| [ ]    | `data/maps/PewterCity/`     |       |
| [ ]    | `data/maps/CeruleanCity/`   |       |
| [ ]    | `data/maps/VermilionCity/`  |       |
| [ ]    | `data/maps/LavenderTown/`   |       |
| [ ]    | `data/maps/CeladonCity/`    |       |
| [ ]    | `data/maps/SaffronCity/`    |       |
| [ ]    | `data/maps/FuchsiaCity/`    |       |
| [ ]    | `data/maps/CinnabarIsland/` |       |

#### Hoenn Cities (inherited from Emerald)

| Status | Map Folder                  | Notes |
| ------ | --------------------------- | ----- |
| [ ]    | `data/maps/LittlerootTown/` |       |
| [ ]    | `data/maps/OldaleTown/`     |       |
| [ ]    | `data/maps/PetalburgCity/`  |       |
| [ ]    | `data/maps/RustboroCity/`   |       |
| [ ]    | `data/maps/DewfordTown/`    |       |
| [ ]    | `data/maps/SlateportCity/`  |       |
| [ ]    | `data/maps/MauvilleCity/`   |       |
| [ ]    | `data/maps/VerdanturfTown/` |       |
| [ ]    | `data/maps/FallarborTown/`  |       |
| [ ]    | `data/maps/LavaridgeTown/`  |       |
| [ ]    | `data/maps/FortreeCity/`    |       |
| [ ]    | `data/maps/LilycoveCity/`   |       |
| [ ]    | `data/maps/MossdeepCity/`   |       |
| [ ]    | `data/maps/SootopolisCity/` |       |
| [ ]    | `data/maps/PacifidlogTown/` |       |
| [ ]    | `data/maps/EverGrandeCity/` |       |

#### Other Maps

| Status | Description                                     | Notes |
| ------ | ----------------------------------------------- | ----- |
| [ ]    | Remaining Johto interiors (Gyms, Marts, Houses) |       |
| [ ]    | Remaining Kanto interiors                       |       |
| [ ]    | Remaining Hoenn routes & interiors              |       |
| [ ]    | Safari Zone maps                                |       |
| [ ]    | Pokemon League / Elite Four maps                |       |
| [ ]    | SS Aqua / S.S. Tidal maps                       |       |
| [ ]    | Battle Frontier maps                            |       |

---

## Phase 2: Extended Pokemon Data

| Status | File                                 | Description                    | ~Strings |
| ------ | ------------------------------------ | ------------------------------ | -------- |
| [ ]    | `src/data/pokemon/pokedex_text.h`    | Pokedex descriptions           | ~460     |
| [ ]    | `src/data/pokemon/pokedex_entries.h` | Category names (SEED, LIZARD…) | ~460     |
| [ ]    | `src/data/text/move_descriptions.h`  | Move descriptions              | ~371     |
| [ ]    | `src/data/text/item_descriptions.h`  | Item descriptions              | ~786     |
| [ ]    | `src/data/text/abilities.h`          | Ability names & descriptions   | ~130     |
| [ ]    | `src/data/text/nature_names.h`       | Nature names                   | ~25      |
| [ ]    | `src/data/text/follower_messages.h`  | Following Pokemon messages     | ~150     |

---

## Phase 3: World & UI

| Status | File                                                 | Description                     | ~Strings |
| ------ | ---------------------------------------------------- | ------------------------------- | -------- |
| [ ]    | `src/data/region_map/region_map_sections_johto.json` | Johto map names                 | —        |
| [ ]    | `src/data/region_map/region_map_sections.json`       | Other map section names         | —        |
| [ ]    | `src/landmark.c`                                     | Landmark names                  | ~50      |
| [ ]    | `src/battle_main.c` (type names array)               | Type names                      | ~18      |
| [ ]    | `src/data/text/trainer_class_names.h`                | Trainer class names             | ~85      |
| [ ]    | `src/data/trainers.h` (trainer names)                | Trainer proper names (optional) | ~700     |
| [ ]    | `src/options_plus_menu.c`                            | Options+ menu labels & tooltips | —        |
| [ ]    | `src/tx_rac_menu.c`                                  | Game setup / challenge menu     | —        |
| [ ]    | `data/text/pokedex_rating.inc`                       | Pokedex rating messages         | —        |
| [ ]    | `data/text/move_tutors.inc`                          | Move tutor dialogue             | —        |

---

## Phase 4: Side Content

| Status | File                                       | Description                   | ~Strings |
| ------ | ------------------------------------------ | ----------------------------- | -------- |
| [ ]    | `src/data/easy_chat/` (all ~25 files)      | Easy Chat word banks          | ~1,000   |
| [ ]    | `data/text/match_call.inc`                 | PokeNav match call dialogue   | ~2,328   |
| [ ]    | `data/text/tv.inc`                         | TV show scripts               | ~2,193   |
| [ ]    | `data/text/contest_strings.inc`            | Contest text                  | —        |
| [ ]    | `data/text/contest_link.inc`               | Contest link text             | —        |
| [ ]    | `data/text/contest_painting.inc`           | Contest painting descriptions | —        |
| [ ]    | `src/data/decoration/header.h`             | Decoration names              | —        |
| [ ]    | `src/data/decoration/description.h`        | Decoration descriptions       | —        |
| [ ]    | `src/data/text/ribbon_descriptions.h`      | Ribbon descriptions           | ~48      |
| [ ]    | `src/data/text/gift_ribbon_descriptions.h` | Gift ribbon descriptions      | ~115     |
| [ ]    | `src/data/text/match_call_messages.h`      | Match call character messages | ~471     |
| [ ]    | `data/text/berries.inc`                    | Berry-related text            | ~157     |
| [ ]    | `src/data/credits.h`                       | Credits (role titles only)    | ~50      |
| [ ]    | `data/text/battle_dome.inc`                | Battle Dome text              | —        |
| [ ]    | `data/text/battle_tent.inc`                | Battle Tent text              | —        |
| [ ]    | `data/text/frontier_brain.inc`             | Frontier Brain dialogue       | —        |
| [ ]    | `data/text/apprentice.inc`                 | Apprentice text               | ~1,952   |
| [ ]    | `data/text/cable_club.inc`                 | Link / multiplayer text       | —        |
| [ ]    | `data/text/lottery_corner.inc`             | Lottery corner text           | —        |
| [ ]    | `data/text/questionnaire.inc`              | Questionnaire text            | —        |
| [ ]    | `data/text/mauville_man.inc`               | Mauville old man stories      | —        |
| [ ]    | `data/text/blend_master.inc`               | Berry blend text              | —        |
| [ ]    | `data/text/event_ticket_1.inc`             | Event ticket text             | —        |
| [ ]    | `data/text/event_ticket_2.inc`             | Event ticket text             | —        |
| [ ]    | `data/text/trick_house_mechadolls.inc`     | Trick House text              | —        |
| [ ]    | `data/text/check_furniture.inc`            | Furniture descriptions        | —        |
| [ ]    | `data/text/abnormal_weather.inc`           | Weather event text            | —        |
| [ ]    | `data/text/braille.inc`                    | Braille puzzle text           | —        |
| [ ]    | `data/text/record_mix.inc`                 | Record mixing text            | —        |
| [ ]    | `data/text/pokemon_news.inc`               | Pokemon news text             | —        |
| [ ]    | `data/text/shoal_cave.inc`                 | Shoal Cave text               | —        |
| [ ]    | `data/text/secret_base_trainers.inc`       | Secret base trainer text      | —        |
| [ ]    | `data/text/surf.inc`                       | Surfing text                  | —        |

---

## Phase 5: Graphics & Assets

| Status | Asset                               | Description                         |
| ------ | ----------------------------------- | ----------------------------------- |
| [ ]    | `graphics/types/move_types.4bpp.lz` | Type icon pixel art (NORMAL, FIRE…) |
| [ ]    | Title screen / logos                | Any English text baked in           |
| [ ]    | Battle UI tilesets                  | Any English text baked in           |

---

## Phase 6: Debug & Low-Priority

| Status | File          | Description        |
| ------ | ------------- | ------------------ |
| [ ]    | `src/debug.c` | Debug menu strings |

---

## Notes

- **Total estimated strings:** ~45,000+
- **Charmap:** French characters already supported — no font changes needed.
- **Max lengths to watch:** Pokemon (10), Move (12), Item (14), Type (6), Trainer class (12).
- **Build command:** `make modern`
- **Test with:** mGBA
- Use official French Pokemon terminology from Pokepedia / Bulbapedia.
