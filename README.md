# Jujutsu Kaisen Cursed Clash Mod Kit — UE 5.1

## Requirements

- Visual Studio 2019: [Download without MS Account](https://gist.github.com/Chenx221/6f4ed72cd785d80edb0bc50c9921daf7#visual-studio-2019) - Grab vs_community.exe
- Retoc: [Repo](https://github.com/trumank/retoc) - [Download](https://github.com/trumank/retoc/releases/download/v0.1.5/retoc_cli-x86_64-pc-windows-msvc.zip)
- Unreal Engine 5.1.1

## Getting Started

1. 
2. Open the JJK Mod Kit menu and click 'Import Game Assets'
3. 

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
