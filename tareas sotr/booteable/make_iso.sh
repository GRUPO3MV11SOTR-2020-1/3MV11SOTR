#!/bin/sh
genisoimage -R -b boot/grub/stage2_eltorito -no-emul-boot -boot-load-size 4 -boot-info-table -o ~/shared/rtos.iso isofiles
