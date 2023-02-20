# erb-daisysp

⚠️ **This repository is a Work In Progress** ⚠️

[![License: MIT](https://img.shields.io/badge/license-MIT-yellow)](https://opensource.org/licenses/MIT)

The `erb-daisysp` project shows how to use [`eurorack-blocks`](https://github.com/ohmtech-rdi/eurorack-blocks) with [`DaisySP`](https://github.com/electro-smith/DaisySP) to develop your own custom Eurorack module. It also provides a thin wrapper around `DaisySP` classes to ease integration with idiomatic `eurorack-blocks` source code.

As with `eurorack-blocks`, testing and debugging can be done in a [virtual Eurorack environment](https://vcvrack.com), and when ready, it can auto-magically generate all the needed files to manufacture the Eurorack module for you to use in a real Eurorack modular system.

This repository is part of the [`eurorack-blocks` documentation](https://eurorack-blocks.readthedocs.io/en/latest/).


## Setting up

Setting up the development environment is described in the
[documentation](https://eurorack-blocks.readthedocs.io/en/latest/getting-started/setup.html).


## Manifest

The thin wrapper provides:
- A way to maximise syntactic compatibility and cohesion with Eurorack-blocks,
- Strong typing and specialized literals to ease reading,
- Block processing, to avoid the cache performance penalty when doing sample-to-sample processing when not really needed (_eg_ outside of a feedback loop).


## License

All files in this repository, excluding `submodules/`, are provided with the MIT license.
