# personal_dot_and_config_files
list of my custom dotfile and configuration


## git configuration (.gitconfig)
Set up the user info and my aliases for git

### Set up
1. Copy the file in the user folder (remove or back if already exist)  
`cp .gitconfig ~/`
2. Open the file and modify the placeholder for email and name  
`vim ~/.gitconfig`

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
