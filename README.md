# personal_dot_and_config_files
List of my custom dotfiles and configurations

## TL&DR
1. **vsCode**: Manually copy "*vscode/vscode_keybindings.json*" content in vsCode
2. **git**: Copy the "*git/.gitconfig*" file to the user folder `cp git/.gitconfig ~/` and update user information
3. **bash**: Append content of "*system/.bashrc*" to the user folder `cat system/.bashrc >> ~/.bashrc`
4. **mouse**: Copy config file `cp mouse/90-evoluent.conf /etc/X11/xorg.conf.d/` then restart the session


## Vs code keybindings (vscode/vscode_keybindings.json)
Set of prefered shortcut for vs code like IDE (vs code, cursor)
- "ctrl+s" saves all the files
- "ctrl+d" duplicate a selection or a line if nothing is selected
- "ctrl+/" is toggling of comment (deactivating a shortcut for that taking precedent over the line comment due du bépo layout)

**BONUS**: install "TODO Highlight" extension

### Set up
Open the IDE `keybindings.json` from the menu, copy and paste the content from the repo file into it.  
(No easy way to append the changes to the existing file `~/.config/Code/User/keybindings.json` since it is an JSON array, and it might already contain other configuration)


## Git configuration (git/.gitconfig)
Set up the user info and my aliases for git

### Set up
1. Copy the file in the user folder (remove or do a backup if it already exist)  
`mkdir ~/.config/git && cp git/.gitconfig ~/.config/git/config`  
or if not on linux:  
`cp git/.gitconfig ~/`
2. Open the file and modify the placeholder for email and name  
`vim ~/.config/git/config`  
or if not on linux:  
`vim ~/.gitconfig`

### ssh key generation
If needed, update the "git_shh_setup.sh" file with you information. Then to create and add a ssh key run:  
.`/git/git_ssh_setup.sh`

## Custom bash prompt (system/.bashrc)
My prefered bash prompt configuration (WIP).  
- Add date and time
- 2 lines prompt for readability of the command
- removing host name (to use only for local computer)
- adding git branch name to the prompt if available

### Set up
In case you already have a ".bashrc" file, it is good to back it up  
`cp ~/.bashrc ~/.bashrc.backup`

Append the custom ".bashrc" file to the existing one (so no lost of previous configuration)  
`cat system/.bashrc >> ~/.bashrc`

If there is no ".bashrc" file in your system, then just copy the file to destination  
`cp system/.bashrc ~/.bashrc`

Activate the new prompt (or it will be activated on next terminal open)  
`source ~/.bashrc`

## Evoluent mouse configuration (mouse/90-evoluent.conf)
My evoluent mouse as the backward button on the third button of the mouse, that makes it not practical, since I keep pressing it without wanting.  
Here is a config file to remap the button in xorg, by disabling the third button, and moving the "going backward" to the thumb button.
 
### Set up
The configuration file needs to be but in "/etc/X11/xorg.conf.d/" (as sudo).  
Then on session restart the mapping should be set.  
`sudo cp mouse/90-evoluent.conf /etc/X11/xorg.conf.d/`

## Custom bépo layout
Files mapping for small personal modification from the original bépo layout.  
Deviation includes:
- inversion of "«" and "»" with "<" and ">" (to have direct access to "<" and ">")
- deactivating the "no-break space" and set it to "_" (to prevent unwanted and breaking spaces when in cap locks)
- inverting "…" with "·" for easy access to the median point
- changing the apostrophe character to have the code safe `'` directly accessible instead of the `’`

### Set up on windows (bepo_layout/windows/bepo_vb_v1_3.klc)
On windows, there is an ".exe" file to install the layout in the `bepo_layout/windows/bepovb13.zip`.

### Set up on linux (bepo_layout/linux/bepo_vb_v1_3.xkb)
The attached file is the mapping use to have the modification on a linux system, but the way to implement it is to use the [linux_personalized_keyboard_layout_script](https://github.com/guyzmuch/linux_personalized_keyboard_layout_script) project that has a script to set up custom layout on linux based operating system.
