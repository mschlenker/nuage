#!/bin/bash

me=` id -u `
if [ "$me" -gt 0 ] ; then
        echo 'Please run this script with root privileges!'
fi

chown -R root:root build-deb
chmod 0755 build-deb/nuage-bridge/debian/usr/bin/*
chmod 0755 build-deb/nuage-bridge/debian/etc/init.d/*
chmod 0755 build-deb/nuage-bridge/debian/DEBIAN/postinst
# chmod 0755 build-deb/avrdude6/debian/usr/local/bin/avrdude
# chmod 0755 build-deb/avrdude6/debian/DEBIAN/postinst

( cd build-deb/nuage-bridge ; dpkg-deb --build debian )
# ( cd build-deb/avrdude6   ; dpkg-deb --build debian )

mv -v build-deb/nuage-bridge/debian.deb nuage-bridge.deb
# mv -v build-deb/avrdude6/debian.deb   avrdude6.deb


