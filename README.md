# SyoBoNic Overlay for FreeBSD

## What is this?

This is the collection of Ports I modified but did not send the patch to the upstream, or sent but not merged yet.  
For the latter case, I will remove the port from here when they merge it.

## How can I use this?

\[!WARNING!\]  
This overlay is NOT fully tested, NOR intended to be used in a production environment.  
Please use at your own risk.

You can use [Poudriere](https://github.com/freebsd/poudriere) to set this repository as an overlay.
   
```sh
poudriere ports -c -p syobonic-overlay -m git -U https://github.com/syobocat/syobonic-overlay_freebsd.git
```
   
You can change the name `syobonic-overlay` to whatever you like.
Then, add `-O syobonic-overlay` to your `poudriere bulk` commands like:
   
```sh
poudriere bulk -j 140amd64 -p default -O syobonic-overlay foo/bar
```

## List of changes

### Added ports

### Modified ports

- `multimedia/obs-studio`: [\[Bug 276728\]](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=276728) Fix BROKEN state when OPTIONS_UNSET+=PULSEAUDIO
- `www/qt6-webengine`: Make audio backend optional
