# Banjo-Kazooie (100.0000%)

<img src="./progress/progress_total.svg">

### Baserom checksums

- `baserom.us.v10.z64`: `1fe1632098865f639e22c11b9a81ee8f29c75d7a`
- `baserom.us.v11.z64`: `ded6ee166e740ad1bc810fd678a84b48e245ab80`
- `baserom.jp.z64`:     `90726d7e7cd5bf6cdfd38f45c9acbf4d45bd9fd8`
- `baserom.pal.z64`:    `bb359a75941df74bf7290212c89fbc6e2c5601fe`

# Building

The following instructions should work on the following platforms:
- Windows 10 x64

Building Instructions Table Of Contents:

### 1. Install dependencies

```cmd
git clone https://github.com/snowboundmage2/personal-banjo-kazooie.git
git submodule update --init --recursive
```

### 2. Add baserom

I am using the US 1.0 version, hopefully specific version shit can be coded out later on, so any rom from any country will work.

Add the file for `US v1.0` as `baserom.us.v10.z64` in the project folder.

(optional): Check the baserom checksum

```cmd
sha1sum baserom.us.v10.z64
```

The output should match the checksum specified above.

### 3. Build

To extract and build everything simply run:

First install
```cmd
git submodule update --init --recursive
mkdir build
cd build
cmake ..
cmake --build .
```


If you want to build a specific module, instead do:

```sh
make <module_id>
```

...where the following are supported values of `<module_id>`
- `core1`
- `core2`
- `MM`
- `TTC`
- `CC`
- `BGS`
- `FP`
- `lair`
- `GV`
- `CCW`
- `RBB`
- `MMM`
- `SM`
- `fight`
- `cutscenes`

### Version Selection

hopefully not ncessary later. Just assume i have us1.0, all other regions/version temporarily ignored for now. 
