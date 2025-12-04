
# Custom set up for bash prompt
# git branch display if available
parse_git_branch() {
    git branch 2> /dev/null | sed -e '/^[^*]/d' -e 's/* \(.*\)/ (\1)/'
}
# |14:30:22 (Mon Oct 13) : user-->[/current/directory] (git branch)
# |$
export PS1="\n\[\033[0;37m\]|\t (\d) : \[\033[0;92m\]\u\[\033[0;94m\]-->\[\033[0;93m\][\[\033[0;95m\]\w\[\033[0;93m\]]\[\033[0;36m\]\$(parse_git_branch)\n\[\033[0;37m\]|\$\[\033[0;97m\] "

