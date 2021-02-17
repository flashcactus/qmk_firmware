prefixcactus' GH60 Satan Layout
=====================
Based on Unxmaal's layout from the QMK repo

##Quantum MK Firmware
For the full Quantum feature list, see the parent readme.md.

* Standard ANSI layout except for sun backspace (directly above the enter key).
* Spacebar acts as space when tapped, Fn when held. Use `SPC`+`B` if you need an actual held down space key.
* Menu acts as menu when tapped, Fn2 when held.
* Space cadet shifts ( `(` and `)` when tapped, act as regular shifts when held). May cause the keyboard to freeze sometimes.
* CapsLock acts as control when held, itself when tapped
* Layer1 (with SPC held):
  * Top row = ``` `~``` `F1-F12` `Ins/Del`
  * Backspace acts as Del in this layer.
  * `IJKL` = arrow cluster; `UO` = Home/End; `P;` = Pgup/Pgdn.
  * Media buttons under arrow cluster.
  * Left side has volume controls and screen backlight buttons, plus QMK Lock key (see layout.c).
* Layer2 (with Menu held): Mouse controls on the left (ESDF to move, WR for buttons), keyboard backlight under that (see layout.c).


See layout.c for the full map.

### Additional Credits
Keymap has been based on various keymaps available from the QMK Repo for the GH60-SATAN and KC60 keyboards.
