hlds-v8
=======

Half Life Dedicated Server with Google V8 JS Engine (a metamod plugin)

### How to build

#### Get files

- download metamod from http://metamod.org/ (version: 1.20)
- download patched HLSDK from http://metamod.sourceforge.net/files/sdk/ (version: 2.3p4)
- fetch Google's V8 source code from http://code.google.com/p/v8/wiki/UsingGit
- fetch hlds-v8 from https://github.com/deejayy/hlds-v8

#### Unpack

    # tar zxfv hlsdk-2.3-p4.tar.gz
    # tar zxfv metamod-1.20-linux.src.tar.gz

#### Build V8

    v8# make dependencies
    v8# make ia32.release i18nsupport=off library=shared

#### Run build.sh

### Using it

Copy ```libv8.so``` from ```v8/out/ia32.release/obj.target/tools/gyp``` to one of the LD_LIBRARY_PATH directory (preferably in the root of the hlds instance you test/use with).

Copy (or symlink) ```hldsv8_i386.so``` to ```cstrike/addons/hldsv8/``` directory and append the following line to the ```cstrike/addons/metamod/plugins.ini``` file:

    linux plugins/hldsv8/hldsv8_i386.so v8

Run hlds as usual.

### Proof-of-Concept

JS source:

    function ClientConnect(name, address) {
        console.log('A client connected! Name: ' + name + ', ip: ' + address);
    }

Server log:

    L 03/06/2014 - 08:19:01: "deejayy<1><STEAM_0:...><>" connected, address "1.2.3.4:27005"
    L 03/06/2014 - 08:19:01: A client connected! Name: deejayy, ip: 1.2.3.4:27005
    
### Very-very WIP

As you can see in the source, the JS snippet is built in and only two dllapi callbacks are used to demonstrate the conception. Feel free to fork or contribute the project.
