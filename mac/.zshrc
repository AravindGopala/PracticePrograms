if [ -f "$HOME/.zsh_aliases" ] ; then
    . "$HOME/.zsh_aliases"
fi

# Which plugins would you like to load?
# Standard plugins can be found in $ZSH/plugins/
# Custom plugins may be added to $ZSH_CUSTOM/plugins/
# Example format: plugins=(rails git textmate ruby lighthouse)
# Add wisely, as too many plugins slow down shell startup.
#plugins=(
#zsh-autosuggestions
#git
#)

#source #{HOMEBREW_PREFIX}/share/zsh-autosuggestions/zsh-autosuggestions.zsh

#precmd() { eval "$PROMPT_COMMAND" }

#set -o PROMPT_SUBST
#autoload -U colors && colors
#export GIT_RADAR_COLOR_BRANCH='%F[cyan]'
#export GIT_RADAR_FORMAT='[%{remote} "%{branch}"%{local}%{changes}]'
#PROMPT='${(r:$COLUMNS::— :)}'
#PROMPT=$PROMPT'%n@%m % '
#PROMPT=:» "
#export PROMPT="%1/%\$(git-radar --zsh --fetch) "
#PROMPT='%F{cyan}%n%f:~$'

#set -o PROMPT_SUBST
#export PROMPT="$PROMPT\$(git-radar --zsh --fetch) "
#PROMPT='${(r:$COLUMNS::— :)}'
#PROMPT=$PROMPT'%n@%m %~ » '
#PROMPT=$PROMPT"%1/%\$(git-radar --zsh --fetch) "

# MANAGED BY KTMR/ktmr-installer/roles/homebrew
eval "$(/opt/homebrew/bin/brew shellenv)"
# END MANAGED BY KTMR/ktmr-installer/roles/homebrew
# MANAGED BY KTMR/ktmr-installer/roles/nix
# source nix into the environment.
if ! command -v nix &>/dev/null; then
  if [[ -r /nix/var/nix/profiles/default/etc/profile.d/nix-daemon.sh ]]; then
    source /nix/var/nix/profiles/default/etc/profile.d/nix-daemon.sh
  elif [[ -r "$HOME/.nix-profile/etc/profile.d/nix.sh" ]]; then
    source "$HOME/.nix-profile/etc/profile.d/nix.sh"
  fi
fi

# hook direnv into the shell
if command -v direnv &>/dev/null; then
  eval "$( direnv hook "${SHELL}" )"
fi
# END MANAGED BY KTMR/ktmr-installer/roles/nix
# MANAGED BY KTMR/ktmr-installer/roles/ktmr
if [[ -r "${XDG_CONFIG_HOME:-${HOME}/.config}/ktmr/load.sh" ]]; then
  source "${XDG_CONFIG_HOME:-${HOME}/.config}/ktmr/load.sh"
fi
# END MANAGED BY KTMR/ktmr-installer/roles/ktmr
# export PATH="/opt/homebrew/opt/qt@5/bin:$PATH"
export PATH="/opt/homebrew/opt/openjdk/bin:$PATH"
