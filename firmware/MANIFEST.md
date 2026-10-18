# Firmware manifest

Plaintext dumps, grouped by control unit. All reverse-engineered from
the user's own legally obtained reads.

| file | bytes | sha1[:16] |
|---|---|---|
| `firmware/eeproms/NewClonedEprom_021LB.bin` | 4096 | 64c429a78bc7ed70 |
| `firmware/projectB_03G906016B/eeprom_read1.e2p` | 4096 | 2427ca2155f03b3a |
| `firmware/projectB_03G906016B/external_flash_original.bin` | 1048576 | 13134fc2acb68f9f |
| `firmware/projectB_03G906016B/external_flash_stage1.bin` | 1048576 | f193cfca85d22481 |
| `firmware/projectC_03G906021TB/eeprom_95160.bin` | 4096 | 8c45b46ab80db5a8 |
| `firmware/projectC_03G906021TB/flash_M59BW016_2MB.bin` | 2097152 | 2a8cdb18f49d3652 |
| `firmware/projectA_03G906016DJ/eeprom_95320.bin` | 4096 | 291888269c4fdb18 |
| `firmware/projectA_03G906016DJ/external_flash_AM29BL802C.bin` | 1048576 | be9a56db130895a5 |
| `firmware/projectA_03G906016DJ/internal_flash_MPC555.bin` | 459008 | 6274c644d9ffcaf6 |

## Identities
- **Project A — 03G906016DJ** (SW 1037371259, cal 6250): your Octavia. External AM29BL802C @0x800000 + internal MPC555 @0x0 + matched ST95320 EEPROM (VIN TMBDS21ZX52012365). This is the complete matched set.
- **Project B — 03G906016B** (SW 1037369564, cal 5645): sibling unit with WinOLS/TunerPro names and a stage-1 variant; used as the naming reference.
- **Project C — 03G906021TB** (SW 1037391891, cal 2047): EDC16+ on MPC561, 2MB M59BW016 — different CPU/flash map, included for completeness.
