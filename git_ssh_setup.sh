#!/bin/bash

# Base on info from https://docs.github.com/en/authentication/connecting-to-github-with-ssh/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent

# Default values
key_name="github2"
file_path="$HOME/.ssh/$key_name"
passphrase=""

# Requesting email to link to the key
echo "ENTER YOUR GITHUB ADDRESS:"
read email

# Generating the key (passphrase is empty by defaut to prevent promt from ssh-keygen)
echo "GENERATING THE KEY:"
ssh-keygen -t ed25519 -C $email -N "$passphrase" -f $file_path

# (if problem using ssh, add this script to the .bashrc file to launch it automatically at shell starup)
# Start the ssh-agent
# eval "$(ssh-agent -s)"

# List ssh keys
# ssh-add -l

# Add the key to the agent
# ssh-add $file_path

# User report
passphrase_text="with NO passphrase"
if [ -n "$passphrase" ]; then
  passphrase_text="WITH passphrase"
fi
echo ""
echo "SSH key saved $passphrase_text in $file_path"

# Display information to paste into github
echo "NOW, MANUALLY PASTE THE CONTENT OF $file_path.pub INTO GITHUB. FILE CONTENT:"
cat $file_path.pub
