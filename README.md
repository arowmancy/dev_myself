# /dev/myself
## a virtual file driver to create a device /dev/myself

### quick start

when installed, running:
```bash
sudo cat /dev/myself
```
or
```bash
sudo head -c 4 /dev/myself
```

prints stream of random tarot cards:
```text
+T1+C1+S1+P1+W1
```

card formatting:
```regex
/[+-](T(2[0-1]|1[0-9]|[0-9])|[CSPW](1[0-4]|[1-9])){1}(?=[\s+-])/
```


### install

download file and generate keys

```bash
git clone https://github.com/arowmancy/dev_myself.git dev_myself # 1 download
cd dev_myself
sudo make key     # 2 generate key for signing
sudo reboot now   # 3 reboot and enable MOK
  # 1. a blue screen (MOK manager) will appear
  # 2. choose "Enroll MOK"
  # 3. choose "Continue"
  # 4. choose "Yes" (when asked "Enroll the key")
  # 5. enter the password you gave at make sign
  # 6. choose "Reboot" (again)
```

Install module in system

```bash
sudo make full
```

in case you want a fast development life cycle, here is how to load module once

```bash
make build        # 4 compile
sudo make sign    # 5 sign driver module to permit MOK enforcement (security)
sudo make user_load    # 6 load
sudo make user_create  # 7 create /dev/myself
make test         # 8 test if all is ok
```

as usual, to clean your work, run `sudo make clean`


### util

```bash
# installed modules, see #7
lsmod  # list modules
sudo modprobe myself  # load myself driver => creates /dev/myself
sudo depmod  # re-create the module dependency list
sudo modprobe -r myself  # load myself driver => removes /dev/myself

# keys
sudo mokutil --list-new  # list key that will be added at boot
sudo mokutil --reset  # delete future keys
sudo cat /proc/keys  # view your installed keys
dmesg -wH  # kernel log like tail -f

# cheats
sudo modprobe -r myself && \
sudo make full && \
watch -n 1 sudo head -c 4 /dev/myself # update and run
```

### source

*  based on https://github.com/tinmarino/dev_one
*  device driver: https://www.apriorit.com/dev-blog/195-simple-driver-for-linux-os
*  signing driver: https://gist.github.com/Garoe/74a0040f50ae7987885a0bebe5eda1aa
*  MOK: https://ubuntu.com/blog/how-to-sign-things-for-secure-boot


### licence

this project, dev_myself, is licensed under the [GPL v2.0 or later](https://spdx.org/licenses/GPL-2.0-or-later.html)
copyright &copy; 2025 scot reichman (https://github.com/i2097i)
