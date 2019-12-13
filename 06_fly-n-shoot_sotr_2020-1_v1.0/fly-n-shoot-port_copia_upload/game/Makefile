RTOS := flynshoot
ISOIMAGE := rtos.iso
.PHONY: clean default $(RTOS).exe

CC = mgcc
AR = ar
STRIP = strip
CFLAGS = -Wall -Wextra -I$(MARTE)/arch/drivers/svga -I ../port -I ../include
OFLAGS = -s -Os -DNDEBUG
LDFLAGS = -lsvga

default: flynshoot.exe

#flynshoot.exe:
$(RTOS).exe:
	@$(CC) $(CFLAGS) $(OFLAGS) ../qep/source/*.c ../qf/source/*.c *.c $(LDFLAGS) -o $@;
	$(STRIP) --strip-all $@
#Use typing:make rtos.iso
$(ISOIMAGE):$(RTOS).exe
	@cp -v $< ../../booteable-sotr/isofiles/boot/$(RTOS)
	cd ../../booteable-sotr/ && ./make_iso.sh
	@./mover_a_dir_2019.sh
clean: 
	@exec echo -e "\n>> Cleaning... ";
	@find \( -name '*.[oa]' -or -name '*~*' -or -name '*.ali' -or -name '*.log' \
		-or -name '*.exe' -or -name 'mprogram' -or -name 'a.out' \) -print -delete
	@exec echo ">> End Cleaning"
