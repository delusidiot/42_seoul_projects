# install homebrew
rm -rf $HOME/.brew && git clone --depth=1 https://github.com/Homebrew/brew $HOME/.brew && echo 'export PATH=$HOME/.brew/bin:$PATH' >> $HOME/.zshrc && source $HOME/.zshrc && brew update

# install valgrind
# https://github.com/LouisBrunner/valgrind-macos
brew tap LouisBrunner/valgrind

brew install --HEAD LouisBrunner/valgrind/valgrind
