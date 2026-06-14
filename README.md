# Jujutsu Kaisen Cursed Clash Mod Kit — UE 5.1

## Requirements

- Visual Studio 2019: [Download without MS Account](https://gist.github.com/Chenx221/6f4ed72cd785d80edb0bc50c9921daf7#visual-studio-2019) - Grab vs_community.exe
- Retoc: [Repo](https://github.com/trumank/retoc) - [Download](https://github.com/trumank/retoc/releases/download/v0.1.5/retoc_cli-x86_64-pc-windows-msvc.zip)
- Unreal Engine 5.1.1

## Getting Started

1. 
2. Open the JJK Mod Kit menu and click 'Import Game Assets'
3. 

<img width="1167" height="1179" alt="image" src="https://github.com/user-attachments/assets/75ad880b-f9de-4b14-9e92-15566cd52a8c" />

<img width="3840" height="2160" alt="image" src="https://github.com/user-attachments/assets/32b258b4-e4d4-4091-82aa-9e6283a7ed3d" />

<img width="3840" height="2160" alt="image" src="https://github.com/user-attachments/assets/16c1c450-3bb5-4d8a-bace-d32992caeea3" />

<img width="3840" height="2160" alt="image" src="https://github.com/user-attachments/assets/b9b4be63-0106-445e-89ac-90c497d37d8f" />

<img width="3840" height="2160" alt="image" src="https://github.com/user-attachments/assets/2a7fc4e1-5500-467d-902f-fbf2116df0dd" />


## Recompiling the Project

Run this command from any terminal **with the Unreal Editor closed** (or press **Ctrl+Alt+F11** inside the editor to Live-Compile without closing it):

```powershell
& "$env:ProgramFiles\Epic Games\UE_5.1\Engine\Build\BatchFiles\Build.bat" `
    JujutsuKaisenCCEditor Win64 Development `
    "$(Get-Location)\JujutsuKaisenCC.uproject" `
    -waitmutex
```

> **Note:** If the editor is open with Live Coding active the build tool will refuse to run.
> Either close the editor first, or use **Ctrl + Alt + F11** inside UE to trigger a hot-reload compile.

## Developer Notes

### Files that currently crash the editor

- Many Animation Blueprints
- Content\Widgets\Commons\WBP_CharacterCaptureEnemy
- Content\Widgets\Commons\WBP_CharacterCapturePlayer.uasset
- Content\Widgets\Commons\WBP_CharacterCaptureSimple.uasset


### Reloading the mod menu
```
import importlib, init_unreal; importlib.reload(init_unreal)
```
