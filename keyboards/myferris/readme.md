# Ferris sweep

![Ferris sweep, top view](https://i.imgur.com/5qCZUv6h.jpg)
![Ferris sweep, bottom view](https://i.imgur.com/ZC47CJth.jpg)

A version of the Ferris keyboard that uses a daughterboard, designed by the fantastic @davidphilipbarr with some input from @pierrechevalier83 for the copper pad. All PCB files are available on the [project's github page](https://github.com/davidphilipbarr/Sweep)

## Keyboard Info

Make example for this keyboard (after setting up your build environment):

    make ferris/sweep:default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the top left key on the left half (or the top right key on the right half) and plug in the controller on that side.
* **Physical reset button**: Briefly press the reset button soldered on the PCB.
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is configured.

