# Translation Progress Tracker - French (FR)

> Companion file to [TRANSLATION_GUIDE.md](./TRANSLATION_GUIDE.md).
> Check off items as they are fully translated. Use `[ ]` (pending), `[~]` (in progress), `[x]` (done).

---

## Phase 1: Core Gameplay Text

| Status | File                              | Description                           | ~Strings |
| ------ | --------------------------------- | ------------------------------------- | -------- |
| [x]    | `src/strings.c`                   | UI & menu strings                     | ~1,100   |
| [x]    | `data/text/birch_speech.inc`      | Prof. Oak intro speech                | ~30      |
| [x]    | `data/text/trainers.inc`          | Trainer battle intro/defeat/post text | ~2,498   |
| [x]    | `src/battle_message.c`            | All in-battle text                    | ~500     |
| [x]    | `src/data/text/species_names.h`   | Pokemon names                         | ~464     |
| [x]    | `src/data/text/move_names.h`      | Move names                            | ~371     |
| [x]    | `src/data/items.h`                | Item names                            | ~786     |
| [x]    | `data/text/obtain_item.inc`       | Item obtain messages                  | —        |
| [x]    | `data/text/save.inc`              | Save-related messages                 | —        |
| [x]    | `data/text/pkmn_center_nurse.inc` | Pokemon Center dialogue               | —        |
| [x]    | `data/text/pc.inc`                | PC storage messages                   | —        |
| [x]    | `data/text/pc_transfer.inc`       | PC transfer messages                  | —        |
| [x]    | `data/text/mart_clerk.inc`        | Shop dialogue                         | —        |

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
| [x]    | `src/data/pokemon/pokedex_text.h`    | Pokedex descriptions           | ~460     |
| [x]    | `src/data/pokemon/pokedex_entries.h` | Category names (SEED, LIZARD…) | ~460     |
| [x]    | `src/data/text/move_descriptions.h`  | Move descriptions              | ~371     |
| [x]    | `src/data/text/item_descriptions.h`  | Item descriptions              | ~786     |
| [x]    | `src/data/text/abilities.h`          | Ability names & descriptions   | ~130     |
| [x]    | `src/data/text/nature_names.h`       | Nature names                   | ~25      |
| [x]    | `src/data/text/follower_messages.h`  | Following Pokemon messages     | ~150     |

---

## Phase 3: World & UI

| Status | File                                                 | Description                     | ~Strings |
| ------ | ---------------------------------------------------- | ------------------------------- | -------- |
| [x]    | `src/data/region_map/region_map_sections_johto.json` | Johto map names                 | —        |
| [x]    | `src/data/region_map/region_map_sections.json`       | Other map section names         | —        |
| [ ]    | `src/landmark.c`                                     | Landmark names                  | ~50      |
| [ ]    | `src/battle_main.c` (type names array)               | Type names                      | ~18      |
| [ ]    | `src/data/text/trainer_class_names.h`                | Trainer class names             | ~85      |
| [ ]    | `src/data/trainers.h` (trainer names)                | Trainer proper names (optional) | ~700     |
| [ ]    | `src/options_plus_menu.c`                            | Options+ menu labels & tooltips | —        |
| [ ]    | `src/tx_rac_menu.c`                                  | Game setup / challenge menu     | —        |
| [x]    | `data/text/pokedex_rating.inc`                       | Pokedex rating messages         | —        |
| [x]    | `data/text/move_tutors.inc`                          | Move tutor dialogue             | —        |

---

## Phase 4: Side Content

| Status | File                                       | Description                   | ~Strings |
| ------ | ------------------------------------------ | ----------------------------- | -------- |
| [ ]    | `src/data/easy_chat/` (all ~25 files)      | Easy Chat word banks          | ~1,000   |
| [x]    | `data/text/match_call.inc`                 | PokeNav match call dialogue   | ~2,328   |
| [ ]    | `data/text/tv.inc`                         | TV show scripts               | ~2,193   |
| [x]    | `data/text/contest_strings.inc`            | Contest text                  | —        |
| [x]    | `data/text/contest_link.inc`               | Contest link text             | —        |
| [x]    | `data/text/contest_painting.inc`           | Contest painting descriptions | —        |
| [ ]    | `src/data/decoration/header.h`             | Decoration names              | —        |
| [ ]    | `src/data/decoration/description.h`        | Decoration descriptions       | —        |
| [ ]    | `src/data/text/ribbon_descriptions.h`      | Ribbon descriptions           | ~48      |
| [ ]    | `src/data/text/gift_ribbon_descriptions.h` | Gift ribbon descriptions      | ~115     |
| [ ]    | `src/data/text/match_call_messages.h`      | Match call character messages | ~471     |
| [x]    | `data/text/berries.inc`                    | Berry-related text            | ~157     |
| [ ]    | `src/data/credits.h`                       | Credits (role titles only)    | ~50      |
| [x]    | `data/text/battle_dome.inc`                | Battle Dome text              | —        |
| [x]    | `data/text/battle_tent.inc`                | Battle Tent text              | —        |
| [x]    | `data/text/frontier_brain.inc`             | Frontier Brain dialogue       | —        |
| [x]    | `data/text/apprentice.inc`                 | Apprentice text               | ~1,952   |
| [x]    | `data/text/cable_club.inc`                 | Link / multiplayer text       | —        |
| [x]    | `data/text/lottery_corner.inc`             | Lottery corner text           | —        |
| [x]    | `data/text/questionnaire.inc`              | Questionnaire text            | —        |
| [x]    | `data/text/mauville_man.inc`               | Mauville old man stories      | —        |
| [x]    | `data/text/blend_master.inc`               | Berry blend text              | —        |
| [x]    | `data/text/event_ticket_1.inc`             | Event ticket text             | —        |
| [x]    | `data/text/event_ticket_2.inc`             | Event ticket text             | —        |
| [x]    | `data/text/trick_house_mechadolls.inc`     | Trick House text              | —        |
| [x]    | `data/text/check_furniture.inc`            | Furniture descriptions        | —        |
| [x]    | `data/text/abnormal_weather.inc`           | Weather event text            | —        |
| [x]    | `data/text/braille.inc`                    | Braille puzzle text           | —        |
| [x]    | `data/text/record_mix.inc`                 | Record mixing text            | —        |
| [x]    | `data/text/pokemon_news.inc`               | Pokemon news text             | —        |
| [x]    | `data/text/shoal_cave.inc`                 | Shoal Cave text               | —        |
| [x]    | `data/text/secret_base_trainers.inc`       | Secret base trainer text      | —        |
| [x]    | `data/text/surf.inc`                       | Surfing text                  | —        |

---

## Phase 5: Graphics & Assets

| Status | Asset                                                     | Description                  |
| ------ | --------------------------------------------------------- | ---------------------------- |
| [x]    | `graphics/types/contest_beauty.png`                       | Beauty type icon pixel art   |
| [x]    | `graphics/types/contest_cool.png`                         | Cool type icon pixel art     |
| [x]    | `graphics/types/contest_cute.png`                         | Cute type icon pixel art     |
| [x]    | `graphics/types/contest_smart.png`                        | Smart type icon pixel art    |
| [x]    | `graphics/types/contest_tough.png`                        | Tough type icon pixel art    |
| [x]    | `graphics/types/bug.png`                                  | Bug type icon pixel art      |
| [x]    | `graphics/types/dark.png`                                 | Dark type icon pixel art     |
| [x]    | `graphics/types/dragon.png`                               | Dragon type icon pixel art   |
| [x]    | `graphics/types/electric.png`                             | Electric type icon pixel art |
| [x]    | `graphics/types/fairy.png`                                | Fairy type icon pixel art    |
| [x]    | `graphics/types/fight.png`                                | Fighting type icon pixel art |
| [x]    | `graphics/types/fire.png`                                 | Fire type icon pixel art     |
| [x]    | `graphics/types/flying.png`                               | Flying type icon pixel art   |
| [x]    | `graphics/types/ghost.png`                                | Ghost type icon pixel art    |
| [x]    | `graphics/types/grass.png`                                | Grass type icon pixel art    |
| [x]    | `graphics/types/ground.png`                               | Ground type icon pixel art   |
| [x]    | `graphics/types/ice.png`                                  | Ice type icon pixel art      |
| [x]    | `graphics/types/normal.png`                               | Normal type icon pixel art   |
| [x]    | `graphics/types/poison.png`                               | Poison type icon pixel art   |
| [x]    | `graphics/types/psychic.png`                              | Psychic type icon pixel art  |
| [x]    | `graphics/types/rock.png`                                 | Rock type icon pixel art     |
| [x]    | `graphics/types/steel.png`                                | Steel type icon pixel art    |
| [x]    | `graphics/types/water.png`                                | Water type icon pixel art    |
| [ ]    | `data/tilesets/primary/general_frontier_east/tiles.png`   | —                            |
| [ ]    | `data/tilesets/primary/general_frontier_west/tiles.png`   | —                            |
| [ ]    | `data/tilesets/primary/johto_general/tiles.png`           | —                            |
| [ ]    | `data/tilesets/primary/johto_north_east/tiles.png`        | —                            |
| [ ]    | `data/tilesets/primary/johto_north_west/tiles.png`        | —                            |
| [ ]    | `data/tilesets/primary/johto_south/tiles.png`             | —                            |
| [ ]    | `data/tilesets/primary/kanto_general/tiles.png`           | —                            |
| [ ]    | `data/tilesets/secondary/battle_dome/tiles.png`           | —                            |
| [ ]    | `data/tilesets/secondary/bike_shop/tiles.png`             | —                            |
| [ ]    | `data/tilesets/secondary/cianwood_city/tiles.png`         | —                            |
| [ ]    | `data/tilesets/secondary/johto_bike_shop/tiles.png`       | —                            |
| [ ]    | `graphics/bag/check_berry.png`                            | —                            |
| [ ]    | `graphics/battle_frontier/tourney_buttons.png`            | —                            |
| [ ]    | `graphics/battle_interface/status.png`                    | —                            |
| [ ]    | `graphics/battle_interface/status2.png`                   | —                            |
| [ ]    | `graphics/battle_interface/status2gen3.png`               | —                            |
| [ ]    | `graphics/battle_interface/status3.png`                   | —                            |
| [ ]    | `graphics/battle_interface/status3gen3.png`               | —                            |
| [ ]    | `graphics/battle_interface/status4.png`                   | —                            |
| [ ]    | `graphics/battle_interface/status4gen3.png`               | —                            |
| [ ]    | `graphics/battle_interface/statusgen3.png`                | —                            |
| [ ]    | `graphics/contest/interface.png`                          | —                            |
| [ ]    | `graphics/contest/results_screen/tiles.png`               | —                            |
| [ ]    | `graphics/easy_chat/button_window.png`                    | —                            |
| [ ]    | `graphics/frontier_pass/bg.png`                           | —                            |
| [ ]    | `graphics/frontier_pass/map_and_card.png`                 | —                            |
| [ ]    | `graphics/frontier_pass/map_screen.png`                   | —                            |
| [ ]    | `graphics/interface/menu_info.png`                        | —                            |
| [ ]    | `graphics/interface/status_icons.png`                     | —                            |
| [ ]    | `graphics/naming_screen/back_button.png`                  | —                            |
| [ ]    | `graphics/naming_screen/ok_button.png`                    | —                            |
| [ ]    | `graphics/naming_screen/page_swap_lower.png`              | —                            |
| [ ]    | `graphics/naming_screen/page_swap_others.png`             | —                            |
| [ ]    | `graphics/naming_screen/page_swap_upper.png`              | —                            |
| [ ]    | `graphics/object_events/pics/misc/mart_light.png`         | —                            |
| [ ]    | `graphics/party_menu/bg.png`                              | —                            |
| [ ]    | `graphics/pokeblock/menu.png`                             | —                            |
| [ ]    | `graphics/pokeblock/use_screen/condition.png`             | —                            |
| [ ]    | `graphics/pokeblock/use_screen/graph.png`                 | —                            |
| [ ]    | `graphics/pokeblock/use_screen/updown.png`                | —                            |
| [ ]    | `graphics/pokedex/area_unknown.png`                       | —                            |
| [ ]    | `graphics/pokedex/hgss/HGSS_tileset_menu_list_DECA.png`   | —                            |
| [ ]    | `graphics/pokedex/hgss/HGSS_tileset_menu_list.png`        | —                            |
| [ ]    | `graphics/pokedex/hgss/HGSS_tileset_menu_search_DECA.png` | —                            |
| [ ]    | `graphics/pokedex/hgss/HGSS_tileset_menu_search.png`      | —                            |
| [ ]    | `graphics/pokedex/hgss/HGSS_tileset_menu1.png`            | —                            |
| [ ]    | `graphics/pokedex/hgss/HGSS_tileset_menu2.png`            | —                            |
| [ ]    | `graphics/pokedex/hgss/HGSS_tileset_menu3.png`            | —                            |
| [ ]    | `graphics/pokedex/menu.png`                               | —                            |
| [ ]    | `graphics/pokedex/search_menu.png`                        | —                            |
| [ ]    | `graphics/pokemon_storage/menu.png`                       | —                            |
| [ ]    | `graphics/pokenav/condition/cancel.png`                   | —                            |
| [ ]    | `graphics/pokenav/condition/graph.png`                    | —                            |
| [ ]    | `graphics/pokenav/left_headers/beauty.png`                | —                            |
| [ ]    | `graphics/pokenav/left_headers/condition.png`             | —                            |
| [ ]    | `graphics/pokenav/left_headers/cool.png`                  | —                            |
| [ ]    | `graphics/pokenav/left_headers/cute.png`                  | —                            |
| [ ]    | `graphics/pokenav/left_headers/main_menu.png`             | —                            |
| [ ]    | `graphics/pokenav/left_headers/match_call.png`            | —                            |
| [ ]    | `graphics/pokenav/left_headers/party.png`                 | —                            |
| [ ]    | `graphics/pokenav/left_headers/ribbons.png`               | —                            |
| [ ]    | `graphics/pokenav/left_headers/search.png`                | —                            |
| [ ]    | `graphics/pokenav/left_headers/smart.png`                 | —                            |
| [ ]    | `graphics/pokenav/left_headers/tough.png`                 | —                            |
| [ ]    | `graphics/pokenav/options/beauty.png`                     | —                            |
| [ ]    | `graphics/pokenav/options/cancel.png`                     | —                            |
| [ ]    | `graphics/pokenav/options/condition.png`                  | —                            |
| [ ]    | `graphics/pokenav/options/cool.png`                       | —                            |
| [ ]    | `graphics/pokenav/options/cute.png`                       | —                            |
| [ ]    | `graphics/pokenav/options/match_call.png`                 | —                            |
| [ ]    | `graphics/pokenav/options/party.png`                      | —                            |
| [ ]    | `graphics/pokenav/options/ribbons.png`                    | —                            |
| [ ]    | `graphics/pokenav/options/search.png`                     | —                            |
| [ ]    | `graphics/pokenav/options/smart.png`                      | —                            |
| [ ]    | `graphics/pokenav/options/tough.png`                      | —                            |
| [ ]    | `graphics/pokenav/region_map/city_zoom_text.png`          | —                            |
| [ ]    | `graphics/shop/money.png`                                 | —                            |
| [ ]    | `graphics/slot_machine/menu.png`                          | —                            |
| [ ]    | `graphics/summary_screen/tiles.png`                       | —                            |
| [ ]    | `graphics/trainer_card/frlg/tiles.png`                    | —                            |
| [ ]    | `graphics/trainer_card/tiles.png`                         | —                            |
| [ ]    | `graphics/union_room_chat/background.png`                 | —                            |
| [ ]    | `graphics/union_room_chat/r_button_labels.png`            | —                            |

| OAM palette | Fichier .pal     | Types combat                                                | Types concours |
| ----------- | ---------------- | ----------------------------------------------------------- | -------------- |
| 13          | move_types_1.pal | Normal, Fighting, Ground, Rock, Steel, Fire, Electric, Dark | Cool, Tough    |
| 14          | move_types_2.pal | Flying, Poison, Ghost, Water, Psychic, Ice, Fairy           | Beauty, Cute   |
| 15          | move_types_3.pal | Bug, Mystery, Grass, Dragon                                 | Smart          |

> HOWTO: edit the .png files in the graphics/types folder. then run the python script apply_pal.py to apply the palette to the .png files.
> apply_pal.py <input.png> <palette.pal> [output.png]

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
