# MTSE CUSTOM INSTRUCTIONS

Forget trying to setup your mac to use qmk, use docker instead.

First, install the Docker Application online: https://docs.docker.com/desktop/install/mac-install/

Run `make git-submodule`

Run `docker build . -t mtseqmk:mtseqmk` to build my custom docker image.

Manually launch the Docker Desktop App if not already running.

run `./compile_docker.sh`
This should have created a file called `handwired_dactyl_manuform_5x6_my_keymap.hex` at the root.

Install QMK toolbox
Flash by opening the hex file in QMK toolbox, resetting the keyboard bootloader, and clicking the Flash button.
