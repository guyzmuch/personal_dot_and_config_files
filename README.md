# personal_dot_and_config_files
List of my custom dotfiles and configurations

## TL&DR
1. **vsCode**: Manually copy "*vscode_keybindings.json*" content in vsCode
2. **git**: Copy the "*.gitconfig*" file to the user folder `cp .gitconfig ~/` and update user information
3. **bash**: Append content of "*.bashrc*" to the user folder `cat .bashrc >> ~/.bashrc`
4. **mouse**: Copy config file `cp 90-evoluent.conf /etc/X11/xorg.conf.d/` then restart the session


## Vs code keybindings (vscode_keybindings.json)
Set of prefered shortcut for vs code like IDE (vs code, cursor)
- "ctrl+s" saves all the files
- "ctrl+d" duplicate a selection or a line if nothing is selected
- "ctrl+/" is toggling of comment (deactivating a shortcut for that taking precedent over the line comment due du bépo layout)

**BONUS**: install "TODO Highlight" extension

### Set up
Open the IDE `keybindings.json` from the menu, copy and paste the content from the repo file into it.  
(No easy way to append the changes to the existing file `~/.config/Code/User/keybindings.json` since it is an JSON array, and it might already contain other configuration)


## Git configuration (.gitconfig)
Set up the user info and my aliases for git

### Set up
1. Copy the file in the user folder (remove or do a backup if it already exist)  
`cp .gitconfig ~/`
2. Open the file and modify the placeholder for email and name  
`vim ~/.gitconfig`

### ssh key generation
If needed, update the "git_shh_setup.sh" file with you information. Then to create and add a ssh key run:  
.`/git_ssh_setup.sh`

## Custom bash prompt (.bashrc)
My prefered bash prompt configuration (WIP).  
- Add date and time
- 2 lines prompt for readability of the command
- removing host name (to use only for local computer)
- adding git branch name to the prompt if available

### Set up
In case you already have a ".bashrc" file, it is good to back it up  
`cp ~/.bashrc ~/.bashrc.backup`

Append the custom ".bashrc" file to the existing one (so no lost of previous configuration)  
`cat .bashrc >> ~/.bashrc`

If there is no ".bashrc" file in your system, then just copy the file to destination  
`cp .bashrc ~/.bashrc`

Activate the new prompt (or it will be activated on next terminal open)  
`source ~/.bashrc`

## Evoluent mouse configuration (90-evoluent.conf)
My evoluent mouse as the backward button on the third button of the mouse, that makes it not practical, since I keep pressing it without wanting.  
Here is a config file to remap the button in xorg, by disabling the third button, and moving the "going backward" to the thumb button.
 
### Set up
The configuration file needs to be but in "/etc/X11/xorg.conf.d/" (as sudo).  
Then on session restart the mapping should be set.  
`cp 90-evoluent.conf /etc/X11/xorg.conf.d/`

## Bépo layout (bepo_vb_v1_3.klc)
KLC file mapping for small personal modification from the original bépo layout.  
Deviation includes:
- inversion of "«" and "»" with "<" and ">"
- deactivating the "no-break space" (and set it to "_")
- inverting "…" with "·" for easy access
- changing the apostrophe character

### Set up
On windows, there is an ".exe" file to install the layout.  
For linux, you have to look up (but by default original bépo layout is already present)
