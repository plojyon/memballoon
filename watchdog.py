import subprocess
import sys

# TODO: configure custom behaviour here
def alarm():
    """Perform action when balloon is popped."""
    print("OOM! stinky")
    subprocess.run("./alarm", shell=True)



try:
    size = sys.argv[1]
except IndexError as err:
    print("Usage: python watchdog.py [size in MiB]")
    exit(0)


proc = subprocess.Popen(f"./balloon {size}", shell=True)

with open(f"/proc/{proc.pid}/oom_score_adj", "w") as f:
    print(1000, file=f)

returncode = 0
try:
    returncode = proc.wait()
except KeyboardInterrupt as err:
    proc.kill()
    print("Safely deflated by keyboard interrupt.")

if returncode != 0:
    alarm()

print("Done")

