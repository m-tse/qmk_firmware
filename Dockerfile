FROM arm64v8/debian

LABEL maintainer=matt.s.tse@gmail.com \
      version=1.0 \
      qmk.version="preonic-1.0-5761-g08210b3aa - sha:06487da"

# Dependencies
RUN apt-get update \
 && apt-get install --no-install-recommends -y build-essential make \
    gcc unzip wget zip gcc-avr binutils-avr avr-libc \
    dfu-programmer dfu-util gcc-arm-none-eabi binutils-arm-none-eabi \
    libnewlib-arm-none-eabi git libusb-dev \
 && apt-get clean \
 && rm -rf /var/lib/apt/lists/* \
 && git config --global http.sslVerify false

# QMK
RUN mkdir -p /usr/share/qmk \
 && cd /usr/share \
 && git clone https://github.com/m-tse/qmk_firmware \
 && cd qmk_firmware \
 && git checkout 28723b0c11a673a750129991aae0e40d156e4280

WORKDIR /usr/share/qmk_firmware
