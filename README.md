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
