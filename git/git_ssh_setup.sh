#!/bin/bash

# Base on info from https://docs.github.com/en/authentication/connecting-to-github-with-ssh/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent

# Default values
key_name="github"
algorithm="ed25519" # you might also want to use "rsa"
bits=2048 # default value for the number of bits (ignored for "ed25519" algorithm )
file_path="$HOME/.ssh/$key_name"
passphrase=""

# Requesting email to link to the key
read -p "ENTER YOUR GITHUB EMAIL ADDRESS: " email

# Generating the key (passphrase is empty by defaut to prevent prompt from ssh-keygen)
echo "GENERATING THE KEY..."
if [ "$algorithm" -eq  "ed25519" ]; then
  ssh-keygen -t $algorithm -C $email -N "$passphrase" -f $file_path
else
  # for other algorithm like "rsa" you include the number of bits
  ssh-keygen -t $algorithm -C $email -N "$passphrase" -b $bits -f $file_path
fi
key_generation_status=$?

if [ $key_generation_status -ne 0 ]; then
  echo "SSH KEY GENERATION FAILED"
  exit 1
fi


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
echo "SSH KEY SAVED $passphrase_text IN $file_path"

# Display information to paste into github
echo "NOW, MANUALLY PASTE THE CONTENT OF $file_path.pub INTO GITHUB. FILE CONTENT:"
cat $file_path.pub
