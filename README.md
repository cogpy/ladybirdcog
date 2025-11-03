# Ladybird

[Ladybird](https://ladybird.org) is a truly independent web browser, using a novel engine based on web standards.

This fork integrates [OpenCog](https://opencog.org/) cognitive architecture to enable autonomous browsing capabilities.

> [!IMPORTANT]
> Ladybird is in a pre-alpha state, and only suitable for use by developers
>

## Features

We aim to build a complete, usable browser for the modern web.

Ladybird uses a multi-process architecture with a main UI process, several WebContent renderer processes,
an ImageDecoder process, and a RequestServer process.

Image decoding and network connections are done out of process to be more robust against malicious content.
Each tab has its own renderer process, which is sandboxed from the rest of the system.

### OpenCog Integration

This fork includes **LibOpenCog**, which provides autonomous browsing capabilities:

- **Autonomous Agent**: AI-driven browser automation and intelligent web interaction
- **Cognitive Architecture**: OpenCog integration framework for reasoning and learning
- **Knowledge Processing**: Observation, analysis, and learning from web content
- **Goal-Directed Behavior**: Autonomous execution of browsing tasks

See [OpenCog Integration documentation](Documentation/OpenCogIntegration.md) for more details.

### Core Components

At the moment, many core library support components are inherited from SerenityOS:

- LibWeb: Web rendering engine
- LibJS: JavaScript engine
- LibWasm: WebAssembly implementation
- LibCrypto/LibTLS: Cryptography primitives and Transport Layer Security
- LibHTTP: HTTP/1.1 client
- LibGfx: 2D Graphics Library, Image Decoding and Rendering
- LibUnicode: Unicode and locale support
- LibMedia: Audio and video playback
- LibCore: Event loop, OS abstraction layer
- LibIPC: Inter-process communication
- **LibOpenCog**: OpenCog cognitive architecture integration

## How do I build and run this?

See [build instructions](Documentation/BuildInstructionsLadybird.md) for information on how to build Ladybird.

Ladybird runs on Linux, macOS, Windows (with WSL2), and many other \*Nixes.

## How do I read the documentation?

Code-related documentation can be found in the [documentation](Documentation/) folder.

## Get in touch and participate!

Join [our Discord server](https://discord.gg/nvfjVJ4Svh) to participate in development discussion.

Please read [Getting started contributing](Documentation/GettingStartedContributing.md) if you plan to contribute to Ladybird for the first time.

Before opening an issue, please see the [issue policy](CONTRIBUTING.md#issue-policy) and the [detailed issue-reporting guidelines](ISSUES.md).

The full contribution guidelines can be found in [`CONTRIBUTING.md`](CONTRIBUTING.md).

## License

Ladybird is licensed under a 2-clause BSD license.
