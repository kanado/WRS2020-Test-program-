import subprocess

def speak(contents):
  subprocess.call(["espeak","-s140 -ven+18 -z",contents])
