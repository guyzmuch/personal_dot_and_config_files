# QMK Configuration for ErgoDox (Falbatech) — Bépo + Layers

This directory contains the QMK configuration for a **Falbatech ErgoDox** (classic wired clone: Teensy 2.0 + MCP23018, same layout as the original ErgoDox). It is **not** a ZSA ErgoDox EZ (no ZSA firmware, RGB stack, or configurator).

QMK target: `ergodox_ez` — the matrix and bootloader match Falbatech / DIY ErgoDox builds even though the folder name says “EZ”.
---

## 📁 **Directory Structure**
your_folder/  
├── keymap.c       # Layer configuration  
├── config.h       # QMK options  
├── rules.mk       # QMK build options (e.g. Auto Shift)  
└── README.md      # This file

---
## 🚀 **Steps to Flash the Keyboard**

### 1️⃣ **Install Dependencies (Linux Mint/Ubuntu/Debian)**
```bash
sudo apt update
sudo apt install -y git python3 python3-pip python3-venv teensy-loader-cli gcc-avr binutils-avr avr-libc
```
On Debian/Ubuntu the CLI binary is `teensy_loader_cli` (underscore); QMK detects it automatically.

---
### 2️⃣ **Install QMK**
```bash
# Clone the QMK repository
git clone https://github.com/qmk/qmk_firmware.git
cd qmk_firmware

# Create python environment
python3 -m venv venv
source venv/bin/activate

# Install Python tools
pip3 install -r requirements.txt
pip install qmk
qmk setup
```

---
### 3️⃣ **Copy Your Files to QMK**
```bash
# Create the directory for your keymap
mkdir -p keyboards/ergodox_ez/keymaps/vince_bepo

# Copy keymap files to this directory
cp /path/to/your/folder/{keymap.c,config.h,rules.mk} keyboards/ergodox_ez/keymaps/vince_bepo/
```
> **Replace `/path/to/your/folder/`** with the actual path to your files.

---
### 4️⃣ **Compile the Firmware**
```bash
cd qmk_firmware
source venv/bin/activate
qmk compile -kb ergodox_ez -km vince_bepo
```
→ The `.hex` file will be generated in:
`qmk_firmware/ergodox_ez_base_vince_bepo.hex`

---
### **Export keymap JSON (visual layout)**

After editing `keymap.c`, export a JSON file to view layers in [QMK Configurator](https://config.qmk.fm):

```bash
cd qmk_firmware
source venv/bin/activate

# Copy latest keymap into QMK first (if you edited files in this folder)
cp /path/to/your/folder/keymap.c keyboards/ergodox_ez/keymaps/vince_bepo/

# Export JSON (--no-cpp is required for most keymaps)
qmk c2json -kb ergodox_ez -km vince_bepo --no-cpp \
  -o /path/to/your/folder/vince_bepo.json
```

Then in the Configurator: **Keyboard settings** (gear icon) → **Import keymap.json** → select `vince_bepo.json`. Use the layer tabs to switch between BASE and FN_NUM.

Re-run this export whenever you change `keymap.c` so the diagram stays in sync with your firmware.

---
### 5️⃣ **Put the Keyboard in Bootloader Mode**
Falbatech ErgoDox boards use a **Teensy 2.0** with the **Halfkay** bootloader (not Atmel DFU). Reset is usually a small button on the Teensy (sometimes reachable through a hole in the case).

1. **Disconnect** the keyboard (or use the reset button if already plugged in).
2. **Press** the Teensy **reset** button briefly (or hold while plugging in USB on some builds).

You have about **7 seconds** to start flashing after entering the bootloader.

---
### 6️⃣ **Flash the Firmware**
```bash
cd qmk_firmware
source venv/bin/activate
qmk flash -kb ergodox_ez -km vince_bepo
```
> If `qmk flash` fails, flash manually (keyboard must be in bootloader mode):
> ```bash
> cd qmk_firmware
> source venv/bin/activate
> teensy_loader_cli -mmcu=atmega32u4 -w -v ergodox_ez_base_vince_bepo.hex
> ```

---
## 🔍 **Troubleshooting**

| **Problem**               | **Solution** |
|---------------------------|--------------|
| `teensy-loader-cli: not found` | Install the flasher:<br>`sudo apt install -y teensy-loader-cli`. Falbatech ErgoDox uses Teensy, not `dfu-util`. |
| Flash window expired | Re-enter bootloader (reset button), then run `qmk flash` within 7 seconds. |
| Permission denied | Add yourself to the `plugdev` group:<br>`sudo usermod -a -G plugdev $USER`<br>Then **log out and back in**. |
| `qmk: command not found` | Activate the QMK virtualenv first:<br>`cd qmk_firmware`<br>`source venv/bin/activate` |
| Keyboard not responding | Press Teensy reset, re-flash. If still dead, check USB cable and that both halves are connected (TRRS). |


---
## 💡 **Notes**
- **To verify** the keyboard is in bootloader mode:
  ```bash
  lsusb | grep -i "Teensy\|Halfkay\|16c0:0478"
  ```
  → Should show something like: `Van Ooijen Technische Informatica Teensy Halfkay Bootloader`.

- **Full reset**: If your keyboard is unresponsive, press and hold the **Reset** button for 10+ seconds to force a restart.
