# Ubuntu on VirtualBox (with copy/paste and shared folders)

This is a written companion to the setup videos. It follows the official VirtualBox and Ubuntu guidance and adds the steps needed to make copy/paste and shared folders work.

## What you need

- VirtualBox installed on your host OS
- An Ubuntu Desktop ISO (LTS recommended)
- At least 25 GB of free disk space and 4 GB RAM available for the VM

## 1) Download Ubuntu

1. Go to `https://ubuntu.com/download/desktop`.
2. Download the latest Ubuntu Desktop LTS ISO.
3. Keep track of where the ISO is saved.

## 2) Create the VM

1. Open VirtualBox and click **New**.
2. Name: `Ubuntu` (or similar). Type: `Linux`. Version: `Ubuntu (64-bit)`.
3. Memory: 4096 MB is comfortable; 2048 MB works if your host is tight on RAM.
4. CPUs: 2 if possible.
5. Create a virtual hard disk: VDI, dynamically allocated, 25-40 GB.
6. Before starting, attach the ISO:
   - **Settings** -> **Storage** -> empty optical drive -> choose the Ubuntu ISO.

## 3) Install Ubuntu in the VM

1. Start the VM and choose **Install Ubuntu**.
2. Keyboard layout: choose your layout and test it.
3. Installation type: **Normal installation**.
4. Updates/third-party: enable **Download updates while installing** (optional).
5. Disk choice: **Erase disk and install Ubuntu** (safe because this is the VM's virtual disk).
6. Set your time zone and create a user account.
7. Finish the install and reboot when prompted.

## 4) Install Guest Additions (needed for copy/paste, resize, shared folders)

VirtualBox features like shared clipboard, drag-and-drop, and auto-resize require Guest Additions inside the Ubuntu VM.

1. In the VM window, choose **Devices -> Insert Guest Additions CD image**.
2. In Ubuntu, open a terminal and run:

```bash
sudo apt update
sudo apt install build-essential dkms linux-headers-$(uname -r)
sudo /media/$USER/VBox_GAs_*/VBoxLinuxAdditions.run
sudo reboot
```

If the CD does not auto-mount, you can mount it manually:

```bash
sudo mkdir -p /mnt/vbox
sudo mount /dev/cdrom /mnt/vbox
sudo /mnt/vbox/VBoxLinuxAdditions.run
```

After reboot, the VM should support seamless mouse, better video resizing, and clipboard features.

## 5) Enable copy/paste and drag-and-drop

1. In VirtualBox, select your VM -> **Settings** -> **General** -> **Advanced**.
2. Set:
   - **Shared Clipboard**: Bidirectional
   - **Drag'n'Drop**: Bidirectional

You can also toggle these from the **Devices** menu while the VM is running.

## 6) Shared folders (optional)

Shared folders make it easy to move files between your host and the Ubuntu VM.

1. VM **Settings** -> **Shared Folders** -> add a folder.
2. Check **Auto-mount** and **Make Permanent**.
3. In Ubuntu, the folder appears under `/media/sf_<name>`.
4. If you get a permission error, add your user to the `vboxsf` group and log out/in:

```bash
sudo usermod -aG vboxsf $USER
```

## Troubleshooting

- **No 64-bit option in VirtualBox**: make sure VT-x/AMD-V is enabled in BIOS/UEFI.
- **Guest Additions install fails**: ensure `build-essential`, `dkms`, and `linux-headers-$(uname -r)` are installed, then rerun the installer.
- **Clipboard/drag and drop not working**: confirm Guest Additions are installed and the VM settings are set to Bidirectional.

## References

- VirtualBox User Manual, Guest Additions (Linux install): `https://www.virtualbox.org/manual/ch04.html#additions-linux`
- VirtualBox User Manual, Shared Clipboard and Drag and Drop: `https://www.virtualbox.org/manual/ch03.html#settings-general-advanced`
- VirtualBox User Manual, Shared Folders: `https://www.virtualbox.org/manual/ch04.html#sharedfolders`
- Ubuntu Desktop install tutorial: `https://ubuntu.com/tutorials/install-ubuntu-desktop`
