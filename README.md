# personal_dot_and_config_files
list of my custom dotfiles and configurations


## Git configuration (.gitconfig)
Set up the user info and my aliases for git

### Set up
1. Copy the file in the user folder (remove or back if already exist)  
`cp .gitconfig ~/`
2. Open the file and modify the placeholder for email and name  
`vim ~/.gitconfig`

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
KLC file mapping for small personnal modification from the original bépo layout.  
Deviation includes:
- inversion of "«" and "»" with "<" and ">"
- deactivating the "no-break space" (and set it to "_")
- inverting "…" with "·" for easy access
- changing the apostrophe character

### Set up
On windows, there is an ".exe" file to install the layout.  
For linux, you have to look up (but by default original bépo layout is already present)
