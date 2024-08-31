#!/bin/bash
cd web/vvtol-vvtol-panel
npm run build
cd ..
cd ..
sudo cp -r web/vvtol-vvtol-panel/dist/ /var/lib/grafana/plugins/vvtol-vvtol-panel
sudo chown -R grafana:grafana /var/lib/grafana/plugins/vvtol-vvtol-panel
sudo chmod 755 /var/lib/grafana/plugins/vvtol-vvtol-panel
sudo systemctl restart grafana-server
