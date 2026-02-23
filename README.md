# Custom Chromium Source Code Modifications

<p align="center">
  Chromium Source Code Customization • Settings • Custom URL's • Custom Branding
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C++-blue">
  <img src="https://img.shields.io/badge/Build-GN%20%7C%20Ninja-orange">
  <img src="https://img.shields.io/badge/Platform-Windows%20%7C%20Linux-lightgrey">
  <img src="https://img.shields.io/badge/Engine-Chromium-green">
  <img src="https://img.shields.io/badge/Project-Type%20%3A%20System%20Modification-success">
</p>

---

## 📖 Overview

This project contains a comprehensive collection of C++ tools, JSON configurations, GN build files, and UI modifications used to create a deeply customized, secure, and custom-branded version of the open-source Chromium browser.

The Chromium codebase is extremely large, containing tens of millions of lines of code. Working with it requires a strong understanding of large-scale C++ architecture, the GN/Ninja build system, and cross-platform OS integration. These patches were developed after several months of studying and reverse-engineering the Chromium source structure to build a browser tailored for specific security, UI, and branding needs.

---

## 🧭 Table of Contents

- [Key Features](#key-features)
- [Repository Structure & How It Works](#-repository-structure--how-it-works)
- [Usage Instructions](#️-usage-instructions)

---

## Key Features

### Automated Name Branding
A custom C++ script automatically scans Chromium resource files and replaces branding text across the entire codebase. Instead of manually editing hundreds of files, the tool performs safe and fast replacements in seconds.

### Search Engine Modification
The browser’s default search engine is permanently enforced across all geographic regions. Standard search engines (like Bing or Yahoo) are wiped out, and users cannot add, modify, or remove search engines through the browser settings, ensuring controlled configuration.

### UI and OS Customizations
This build goes beyond simple appearance changes. It alters how the browser creates desktop shortcuts in Windows, how it routes files in Linux, modifies internal URL schemes (like changing chrome:// to xyz://), and modifies internal menus and side panels of settings.

---

## 📂 Repository Structure & How It Works

This repository is organized by feature. It provides patch files and utilities that are meant to be applied directly to a local fetch of the Chromium code base.

---

### 1. Automated Name Branding
**(Brand_Name_Replace/script.c++)**

Chromium branding is spread across hundreds of Google Resource Directory (.grd and .grdp) files rather than being stored in one single location.

This standalone C++ utility:

- Recursively scans core directories like `src/components` and `src/chrome/app`
- Detects branding strings hidden inside translation and resource files
- Replaces them with your custom brand name
- Reports successful and failed modifications, updating thousands of files automatically

---

### 2. Search Engine Modifications
**(Search_Engine/)**

Chromium normally selects default search engines based on the user’s country. This folder contains the files to stop that behavior.

**template_url_prepopulate_data.cc:**  
Overrides the default search engine configurations for all country codes, forcing the browser to load a single predefined search engine regardless of where in the world it is launched.

**prepopulated_engines.json:**  
Removes standard search providers (Bing, Yahoo, DuckDuckGo) and adds a custom search provider named "Safe" (which you can change to your own engine). It locks the provider to a fixed internal ID.

**search_engines_page.html:**  
Modifies the internal chrome://settings/searchEngines page to remove the UI elements used to manage search engines, turning it into a read-only interface so users cannot change the settings.

---

### 3. OS & Core System Integrations  
**(OS_and_Core_Integrations/)**

These files alter how the browser interacts with the computer's operating system.

**Windows Shortcut Manager (profile_shortcut_manager_win.cc):**  
Modifies the C++ logic that generates Windows desktop shortcuts. This ensures that your custom profile avatars and branded .ico files are correctly mapped and pinned to the Windows taskbar.

**Linux Pathing (chrome_paths_linux.cc):**  
Overrides default directory configurations for customized data routing on Linux environments.

**Custom URL Schemes:**  
Contains instructions and header modifications to globally replace the default chrome:// internal web address scheme with a custom xyz:// protocol across the entire browser.

---

### 4. UI & Menu Modifications  
**(UI_and_Menu_Modifications/)**

These files overhaul the internal menus and visual features of the browser.

**Settings Menu Overhaul:**  
Patches the internal DOM (settings.html, settings_menu.html) to rebrand core navigation items (for example, changing "Profiles" to "XYZ Profiles").

**Side Panel Customization:**  
Includes heavily modified HTML and CSS components to customize the browser's side panel features, including Bookmarks, the Reading List, and User Notes.

---

### 5. Themes & Assets  
**(Themes_and_Assets/)**

This folder contains the visual assets required to compile the new imagery directly into the browser executable.

- Contains custom `.ico` (icons), `.png`, and `.jpg` logo assets.
- Includes modified `BUILD.gn` and `.grd` resource files so the build system knows how to package these new images into the final software.

---

## ⚙️ Usage Instructions

**Note:** You must have the Chromium `depot_tools` installed and a full source tree fetched before applying these patches.

---

### Step 1 — Fetch the Source Code
Download and set up the official Chromium source tree on your local machine using standard Chromium build instructions.

### Step 2 — Apply Branding
Compile and run the custom `script.c++` file, pointing the directory paths in the script to your local Chromium source folders (like `src/components` and `src/chrome/app`).

### Step 3 — Apply OS, UI, and Search Patches
Copy the respective target files from this repository's folders and replace the original files inside your local `src/` tree.

### Step 4 — Build Chromium

```bash
autoninja -C out/Default chrome
