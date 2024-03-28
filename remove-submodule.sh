SUBMODULE_PATH="external/influxdb-cpp" && \
git rm -f $SUBMODULE_PATH && \
git submodule deinit -f $SUBMODULE_PATH && \
rm -rf .git/modules/$SUBMODULE_PATH && \
git config -f .git/config --remove-section submodule.$SUBMODULE_PATH && \
git commit -m "Removed submodule $SUBMODULE_PATH"
