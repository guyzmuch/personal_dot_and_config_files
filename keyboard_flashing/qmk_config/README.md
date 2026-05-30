# QMK Configuration for ErgoDox EZ / ZSA (Bépo + Layers)

This directory contains the QMK configuration for your **ErgoDox EZ** or ZSA-compatible keyboard, with:
- **BASE Layer**: Bépo layout + temporary access to Fn/num layer.
- **FN_NUM Layer**: Function keys + numpad + accessible dot (for IPs, versions, etc.).

---

## 📁 **Directory Structure**
your_folder/  
├── keymap.c    # Layer configuration  
├── config.h    # QMK options (Autoshift, etc.)  
└── README.md   # This file

---
## 🚀 **Steps to Flash the Keyboard**

### 1️⃣ **Install Dependencies (Linux Mint/Ubuntu/Debian)**
```bash
sudo apt update
sudo apt install -y git python3 python3-pip python3-venv dfu-util gcc-avr binutils-avr avr-libc
```

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

# Copy keymap.c and config.h to this directory
cp /path/to/your/folder/keymap.c keyboards/ergodox_ez/keymaps/vince_bepo/
cp /path/to/your/folder/config.h keyboards/ergodox_ez/keymaps/vince_bepo/
```
> **Replace `/path/to/your/folder/`** with the actual path to your files.

---
### 4️⃣ **Compile the Firmware**
```bash
qmk compile -kb ergodox_ez -km vince_bepo
```
→ The `.hex` file will be generated in:
`qmk_firmware/.build/ergodox_ez_vince_bepo.default.hex`

---
### 5️⃣ **Put the Keyboard in DFU Mode (Bootloader)**
1. **Disconnect** the keyboard.
2. **Hold down** the **Reset** button (usually on the back of the keyboard).
3. **Plug in** the keyboard via USB **while holding the button**.
4. **Release** the button after **3 seconds**.

---
### 6️⃣ **Flash the Firmware**
```bash
qmk flash -kb ergodox_ez -km vince_bepo
```
> If this fails, use `dfu-util` manually:
> ```bash
> dfu-util -D .build/ergodox_ez_vince_bepo.default.hex -a 0 -R
> ```

---
---
## 🔍 **Troubleshooting**

| **Problem**               | **Solution** |
|---------------------------|--------------|
| `dfu-util: no DFU device` | Ensure the **Reset** button is held **before** plugging in the keyboard. |
| Permission denied | Add yourself to the `plugdev` group:<br>`sudo usermod -a -G plugdev $USER`<br>Then **restart your session**. |
| `qmk: command not found` | Add `~/.local/bin` to your `PATH`:<br>`echo 'export PATH="$HOME/.local/bin:$PATH"' >> ~/.bashrc`<br>`source ~/.bashrc` |
| Keyboard not responding | Retry the DFU procedure. Wait 10 minutes (automatic reset may occur). |

---
---
## 📌 **Key Features**

| **Feature**               | **Key**                     | **Layer** |
|---------------------------|-----------------------------|-----------|
| Temporary access to FN_NUM | **Home** (right thumb)      | BASE      |
| Dot (instead of comma)    | **DOT_MAC** (row 4, right hand) | FN_NUM |
| Start of line (Mac)       | **Cmd + ←**                 | MAC       |
| End of line (Mac)         | **Cmd + →**                 | MAC       |
| Microphone toggle (Mac)   | **MIC_TOG** (row 4, right hand) | MAC   |
| Caps Lock                 | **Caps Lock** (left thumb)  | MAC       |

---
## 💡 **Notes**
- **To verify** the keyboard is in DFU mode:
  ```bash
  lsusb | grep -i "Atmel"
  ```
  → Should display: `Atmel Corp. ATmega32U4 DFU`.

- **Full reset**: If your keyboard is unresponsive, press and hold the **Reset** button for 10+ seconds to force a restart.
