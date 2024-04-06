import subprocess

def write_to_lcd(message):
    process = subprocess.Popen(["./lcdDriverinput1", message], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    stdout, stderr = process.communicate()
    if stderr:
        print("Fejl:", stderr.decode())

write_to_lcd("Det er tid til at slukke, godnat")
