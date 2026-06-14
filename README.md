# Jujutsu Kaisen Cursed Clash Mod Kit — UE 5.1

A modding toolkit for *Jujutsu Kaisen Cursed Clash*. The repository ships the decompiled C++ source, editor plugins, and Python tooling. **Game assets are not included** — you extract them from your own copy of the game.

---

## What You Need

| Requirement | Notes |
|---|---|
| **Jujutsu Kaisen Cursed Clash** (Steam) | You must own and install the game. The mod kit reads pak files from your install. |
| **Unreal Engine 5.1.1** | Install via the Epic Games Launcher. This project is pinned to UE 5.1. |
| **Visual Studio 2019** | Desktop development with C++ workload. [Download without MS Account](https://gist.github.com/Chenx221/6f4ed72cd785d80edb0bc50c9921daf7#visual-studio-2019) — grab `vs_community.exe`. |
| **~60 GB free disk space** | The import pipeline needs ~50 GB temporarily while unpacking paks, plus space for the extracted assets that stay in the project. |
| **Windows 64-bit** | Primary supported platform. |

The `Tools/` folder should already contain `retoc.exe`, `oo2core_9_win64.dll` (Oodle decompression), and `jjkue.exe`. If `retoc.exe` is missing, download it from the [retoc releases page](https://github.com/trumank/retoc/releases/download/v0.1.5/retoc_cli-x86_64-pc-windows-msvc.zip) and place it in `Tools/`.

---

## Setup

### 1. Clone the repository

```powershell
git clone <repo-url> JujutsuKaisenCC
cd JujutsuKaisenCC
```

The repo intentionally excludes most game content. After setup you will have source code, config, plugins, Python scripts, and mod templates under `Content/Mods/`.

### 2. Enable the Python Editor Script Plugin

The **JJK Mod Kit** menu is registered by `Content/Python/init_unreal.py`, which runs automatically on editor startup.

1. Open **Edit → Plugins**.
2. Search for **Python Editor Script Plugin** and enable it.
3. Restart the editor when prompted.

On first launch you may also be asked to enable other project plugins (`JJKModKit`, `BlueprintUncooker`, etc.) — accept those as well.

### 3. Build the project

**Option A — open the project (easiest for first time)**

Double-click `JujutsuKaisenCC.uproject`. When prompted, choose **Yes** to rebuild missing modules. The first compile can take 15–30+ minutes depending on your machine.

**Option B — build from the terminal**

Close the Unreal Editor first, then from the project root:

```powershell
.\build.ps1
```

Or run the build command directly:

```powershell
& "$env:ProgramFiles\Epic Games\UE_5.1\Engine\Build\BatchFiles\Build.bat" `
    JujutsuKaisenCCEditor Win64 Development `
    "$(Get-Location)\JujutsuKaisenCC.uproject" `
    -waitmutex
```

> **Note:** If the editor is open with Live Coding active, the build tool will refuse to run. Either close the editor, or press **Ctrl + Alt + F11** inside UE to trigger a live-reload compile instead.

After a successful build, open `JujutsuKaisenCC.uproject`. You should see **JJK Mod Kit** in the main menu bar.

---

## Import Game Assets

This is a one-time step that unpacks the game's cooked pak files and copies them into the project's `Content/` folder.

### Before you start

1. **Install the game** via Steam (default path shown below).
2. **Confirm `Tools/retoc.exe` exists.**
3. **Set the game executable path** (skip if you use the default Steam install):
   - **JJK Mod Kit → Settings**
   - Set **Game Exe Path** to your `Jujutsu Kaisen CC.exe`, e.g.:
     ```
     C:\Program Files (x86)\Steam\steamapps\common\Jujutsu Kaisen CC\Jujutsu Kaisen CC\Binaries\Win64\Jujutsu Kaisen CC.exe
     ```
   - The import tool derives the pak folder automatically: `<game root>/Content/Paks`.

### Run the import

1. Open the project in the Unreal Editor.
2. Go to **JJK Mod Kit → Setup → Import Game Assets**.
3. Read the confirmation dialog and click **Yes**.

The pipeline runs five phases:

| Phase | What it does |
|---|---|
| 1 | Runs **retoc** to convert the game's IoStore/Zen pak files into legacy format, writing output to `<game>/Content/Paks/Data/` |
| 2 | Creates **AnimBlueprint stubs** in the project for every `ABP_*` / `*_ABP` asset found in the extracted data |
| 3 | Deletes the original ABP files from the extracted data (they crash the editor if imported as-is) |
| 4 | Deletes three character-capture widget files that also crash the editor |
| 5 | Moves the remaining extracted content into the project's `Content/` folder |

**Expect the editor to be mostly unresponsive during phase 1.** The whole process typically takes 5–15 minutes and uses ~50 GB of temporary disk space under the game's `Content/Paks/Data/` folder (cleaned up automatically at the end).

When finished, **restart the editor** so new assets appear in the Content Browser.

### After import

Run **JJK Mod Kit → Asset Tools → Stub Character-Capture WBPs** to create placeholder widgets for the three capture screens that were removed during import:

- `WBP_CharacterCaptureEnemy`
- `WBP_CharacterCapturePlayer`
- `WBP_CharacterCaptureSimple`

Without these stubs, references to those widgets may cause issues when browsing certain assets.

---

## Verify Everything Works

After import and an editor restart, you should see game folders under `Content/` (Characters, Widgets, Maps, Effects, etc.). Open a few assets in the Content Browser to confirm they load.

If the **JJK Mod Kit** menu is missing, open the Output Log and check for Python errors. You can reload the menu manually:

```python
import importlib, init_unreal; importlib.reload(init_unreal)
```

Run that in **Window → Developer Tools → Output Log** (Python console), or via **Tools → Execute Python Script**.

---

## Making Mods (Brief)

Once assets are imported:

1. **JJK Mod Kit → New Mod** — creates a folder under `Content/Mods/` with a `manifest.json`.
2. Edit or override game assets inside your mod folder.
3. **JJK Mod Kit → Cook & Export All Mods** — cooks and copies mods to the game's `Content/Mods/` folder (derived from your Game Exe Path setting).

For overriding individual game assets that live in protected directories, use **Cook & Export Asset Overrides** and the **Core Packages to Cook** list in **Edit → Project Settings → Plugins → JJK Mod Kit**.

---

## Troubleshooting

### "Paks directory not found"

The Game Exe Path in **JJK Mod Kit → Settings** is wrong or blank. Point it at `Jujutsu Kaisen CC.exe` and try again.

### "retoc executable not found"

Place `retoc.exe` in the project's `Tools/` folder.

### retoc fails or exits with an error

- Make sure the game is fully installed and you can launch it normally.
- Check the **Output Log** for `[retoc]` lines.
- Confirm `Tools/oo2core_9_win64.dll` is present (needed for Oodle-compressed pak data).

### Build fails / missing modules

Regenerate project files: right-click `JujutsuKaisenCC.uproject` → **Generate Visual Studio project files**, then rebuild.

### Editor crashes when opening certain assets

Some assets are known to be problematic even after stubbing. See **Developer Notes** below.

---

## Developer Notes

### Files that currently crash the editor

- Many Animation Blueprints (original cooked ABPs — the import replaces these with stubs)
- `Content/Widgets/Commons/WBP_CharacterCaptureEnemy`
- `Content/Widgets/Commons/WBP_CharacterCapturePlayer`
- `Content/Widgets/Commons/WBP_CharacterCaptureSimple`

Use the stub tools under **JJK Mod Kit → Asset Tools** rather than opening the original cooked versions.

### Recompiling the project

Run this command from any terminal **with the Unreal Editor closed** (or press **Ctrl+Alt+F11** inside the editor to Live-Compile without closing it):

```powershell
& "$env:ProgramFiles\Epic Games\UE_5.1\Engine\Build\BatchFiles\Build.bat" `
    JujutsuKaisenCCEditor Win64 Development `
    "$(Get-Location)\JujutsuKaisenCC.uproject" `
    -waitmutex
```

### Reloading the mod menu

```python
import importlib, init_unreal; importlib.reload(init_unreal)
```
