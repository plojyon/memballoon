# Memory balloon

Inflate a memory balloon process with a high OOM score and a watchdog process that triggers a warning when the balloon pops.

## Setup
```sh
$ gcc balloon.c -o balloon
```

## Usage
```sh
$ python watchdog.py 300
```
The number `300` indicates the size of the balloon in megabytes.

Add an executable file `alarm` (script or otherwise) or configure a custom response in `watchdog.py`.

