#!/bin/sh
# Builds BareDroidNX.nro using the devkitPro Docker image via Podman.
# No local toolchain needed — just run this script.
exec podman run --rm \
    -v "$(pwd)":/project:Z \
    -w /project \
    docker.io/devkitpro/devkita64:latest \
    make "$@"
