#!/bin/bash

# Path to package.json
PACKAGE_JSON="web/vvtol-vvtol-panel/package.json"

# Function to bump version
bump_version() {
    # Read current version
    VERSION=$(grep '"version":' $PACKAGE_JSON | sed 's/.*: "\(.*\)".*/\1/')
    
    # Split version into parts
    IFS='.' read -ra ADDR <<< "$VERSION"
    MAJOR="${ADDR[0]}"
    MINOR="${ADDR[1]}"
    PATCH="${ADDR[2]}"
    
    # Increment patch version
    PATCH=$((PATCH + 1))
    
    # New version
    NEW_VERSION="$MAJOR.$MINOR.$PATCH"
    
    # Update package.json
    sed -i "s/\"version\": \"$VERSION\"/\"version\": \"$NEW_VERSION\"/" $PACKAGE_JSON
    
    echo "Version bumped from $VERSION to $NEW_VERSION"
}

# Bump version
bump_version

# Rest of your original script
cd web/vvtol-vvtol-panel
npm run build

# Remove existing plugin directory if it exists
sudo rm -rf /var/lib/grafana/plugins/vvtol-vvtol-panel

# Copy the contents of dist to the plugin directory
sudo cp -r dist/ /var/lib/grafana/plugins/vvtol-vvtol-panel

cd ../..

sudo chown -R grafana:grafana /var/lib/grafana/plugins/vvtol-vvtol-panel
sudo chmod 755 /var/lib/grafana/plugins/vvtol-vvtol-panel
sudo systemctl stop grafana-server
sudo systemctl start grafana-server