# Custom Chromium Build Patches

This project contains a set of C++ tools, configuration files, and UI modifications used to create a secure, custom-branded version of the open-source Chromium browser.

The Chromium codebase is extremely large, with tens of millions of lines of code. Working with it requires understanding large-scale C++ architecture as well as the GN/Ninja build system. These patches were developed after several months of studying and reverse-engineering the Chromium source structure to build a browser tailored for specific branding and security needs.

---

## Key Features

### Brand Name Replace

A custom C++ script automatically scans Chromium resource files and replaces branding text across the entire code base. Instead of manually editing hundreds of files, the tool performs safe and fast replacements in seconds.

### Search Engine Modifications

The browser’s default search engine is permanently enforced across all regions. Users cannot add, modify, or remove search engines through browser settings, ensuring consistent behavior and controlled configuration.

---

## 📂 Repository Structure & How It Works

This repository provides patch files and utilities that are applied directly to a local Chromium source build.

---

### 1. Branding Modifier  
**(Brand_Name_Replace/script.c++)**

Chromium branding is spread across many Google Resource Directory (.grd and .grdp) files rather than stored in one location.

This standalone C++ custom written script:

- Recursively scans directories such as `src/components` and `src/chrome/app`
- Detects branding strings inside resource files
- Replaces them with a custom brand name
- Reports successful and failed modifications

The process updates thousands of files automatically.

---

### 2. Search Engine Core  
**(Search_Engine/template_url_prepopulate_data.cc)**

Chromium normally selects default search engines based on the user’s country.

This modified file:

- Overrides default search engine configurations for all country codes
- Forces the browser to load a single predefined search engine
- Ensures consistent behavior regardless of geographic location

---

### 3. Engine Configuration  
**(Search_Engine/prepopulated_engines.json)**

This configuration:

- Removes standard search providers such as Bing, Yahoo, and DuckDuckGo
- Adds a custom search provider named “Safe (You can replace it to your own engine)”
- Locks the provider to a fixed internal ID

---

### 4. Settings UI Lockdown  
**(Search_Engine/search_engines_page.html)**

The internal `chrome://settings/searchEngines` page is modified to prevent user interaction.

Changes include:

- Removing UI elements used to manage search engines
- Converting the page into a read-only interface
- Preventing configuration changes from the browser settings panel

---

## ⚙️ Usage Instructions

**Note:** Chromium `depot_tools` and a fully downloaded source tree are required before applying these patches.

### Step 1 — Apply Branding

Compile and run `script.c++`, pointing the directory paths to your local Chromium source folders (`src/components` and `src/chrome/app`).

### Step 2 — Apply Search Engine Patches

Replace the corresponding `.cc`, `.json`, and `.html` files in your Chromium source tree with the modified versions from this repository.

### Step 3 — Build Chromium

Recompile the browser using Ninja:

```bash
autoninja -C out/Default chrome
