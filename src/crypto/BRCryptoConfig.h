//
//  BRCryptoConfig.h
//  BRCore
//
//  Created by Ed Gamble on 12/9/19.
//  Copyright © 2019 Breadwinner AG. All rights reserved.
//
//  See the LICENSE file at the project root for license information.
//  See the CONTRIBUTORS file at the project root for a list of contributors.

#define HAS_BTC_TESTNET     1
#define HAS_BCH_TESTNET     1
#define HAS_BSV_TESTNET     0
#define HAS_LTC_TESTNET     0
#define HAS_ETH_TESTNET     1
#define HAS_XRP_TESTNET     0
#define HAS_HBAR_TESTNET    0
#define HAS_XTZ_TESTNET     0

#if !defined DEFINE_NETWORK
#define DEFINE_NETWORK(type, networkId, name, network, isMainnet, height, confirmations, confirmationPeriodInSeconds)
#endif

#if !defined DEFINE_NETWORK_FEE_ESTIMATE
#define DEFINE_NETWORK_FEE_ESTIMATE(networkId, amount, tier, confirmationTimeInMilliseconds)
#endif

#if !defined DEFINE_CURRENCY
#define DEFINE_CURRENCY(networkId, currencyId, name, code, type, address, verified)
#endif

#if !defined DEFINE_UNIT
#define DEFINE_UNIT(currencyId, name, code, decimals, symbol)
#endif

#if !defined DEFINE_ADDRESS_SCHEMES
#define DEFINE_ADDRESS_SCHEMES(networkId, defaultScheme, otherSchemes...)
#endif

#if !defined DEFINE_MODES
#define DEFINE_MODES(networkId, defaultMode, otherModes...)
#endif

// MARK: - BTC

#define NETWORK_NAME    "Bitcoin"
DEFINE_NETWORK (CRYPTO_NETWORK_TYPE_BTC,  "bitcoin-mainnet", NETWORK_NAME, "mainnet", true, 668821, 6, 10 * 60)
DEFINE_NETWORK_FEE_ESTIMATE ("bitcoin-mainnet", "18", "10m", 10 * 60 * 1000)
DEFINE_CURRENCY ("bitcoin-mainnet",     "bitcoin-mainnet:__native__",   NETWORK_NAME,  CRYPTO_NETWORK_CURRENCY_BTC,  "native",   NULL,   true)
    DEFINE_UNIT ("bitcoin-mainnet:__native__",      "Satoshi",    "sat",      0,      "SAT")
    DEFINE_UNIT ("bitcoin-mainnet:__native__",      NETWORK_NAME, "btc",      8,      "₿")
DEFINE_ADDRESS_SCHEMES  ("bitcoin-mainnet", CRYPTO_ADDRESS_SCHEME_BTC_SEGWIT,   CRYPTO_ADDRESS_SCHEME_BTC_LEGACY)
DEFINE_MODES            ("bitcoin-mainnet", CRYPTO_SYNC_MODE_API_ONLY,          CRYPTO_SYNC_MODE_P2P_ONLY)

DEFINE_NETWORK (CRYPTO_NETWORK_TYPE_BTC,  "bitcoin-testnet", NETWORK_NAME, "testnet", false, 1931985, 6, 10 * 60)
DEFINE_NETWORK_FEE_ESTIMATE ("bitcoin-testnet", "18", "10m", 10 * 60 * 1000)
DEFINE_CURRENCY ("bitcoin-testnet",     "bitcoin-testnet:__native__",   NETWORK_NAME,  CRYPTO_NETWORK_CURRENCY_BTC,  "native",   NULL,   true)
    DEFINE_UNIT ("bitcoin-testnet:__native__",      "Satoshi",    "sat",      0,      "SAT")
    DEFINE_UNIT ("bitcoin-testnet:__native__",      NETWORK_NAME, "btc",      8,      "₿")
DEFINE_ADDRESS_SCHEMES  ("bitcoin-testnet", CRYPTO_ADDRESS_SCHEME_BTC_SEGWIT,   CRYPTO_ADDRESS_SCHEME_BTC_LEGACY)
#if HAS_BTC_TESTNET
DEFINE_MODES            ("bitcoin-testnet", CRYPTO_SYNC_MODE_API_ONLY,          CRYPTO_SYNC_MODE_P2P_ONLY)
#else
DEFINE_MODES            ("bitcoin-testnet", CCRYPTO_SYNC_MODE_P2P_ONLY)
#endif
#undef NETWORK_NAME

// MARK: - BCH

#define NETWORK_NAME    "Bitcoin Cash"
DEFINE_NETWORK (CRYPTO_NETWORK_TYPE_BCH,  "bitcoincash-mainnet", NETWORK_NAME, "mainnet", true, 673068, 6, 10 * 60)
DEFINE_NETWORK_FEE_ESTIMATE ("bitcoincash-mainnet", "2", "10m", 20 * 60 * 1000)
DEFINE_CURRENCY ("bitcoincash-mainnet",     "bitcoincash-mainnet:__native__",   NETWORK_NAME,  CRYPTO_NETWORK_CURRENCY_BCH,  "native",   NULL,   true)
    DEFINE_UNIT ("bitcoincash-mainnet:__native__",      "Satoshi",    "sat",      0,      "SAT")
    DEFINE_UNIT ("bitcoincash-mainnet:__native__",      NETWORK_NAME, "bch",      8,      "BCH")
DEFINE_ADDRESS_SCHEMES  ("bitcoincash-mainnet", CRYPTO_ADDRESS_SCHEME_BTC_LEGACY)
DEFINE_MODES            ("bitcoincash-mainnet", CRYPTO_SYNC_MODE_API_ONLY, CRYPTO_SYNC_MODE_P2P_ONLY)

DEFINE_NETWORK (CRYPTO_NETWORK_TYPE_BCH,  "bitcoincash-testnet", NETWORK_NAME, "testnet", false, 1432976, 6, 10 * 60)
DEFINE_NETWORK_FEE_ESTIMATE ("bitcoincash-testnet", "2", "10m", 20 * 60 * 1000)
DEFINE_CURRENCY ("bitcoincash-testnet",     "bitcoincash-testnet:__native__",   NETWORK_NAME,  CRYPTO_NETWORK_CURRENCY_BCH,  "native",   NULL,   true)
    DEFINE_UNIT ("bitcoincash-testnet:__native__",      "Satoshi",    "sat",      0,      "SAT")
    DEFINE_UNIT ("bitcoincash-testnet:__native__",      NETWORK_NAME, "bch",      8,      "BCH")
DEFINE_ADDRESS_SCHEMES  ("bitcoincash-testnet", CRYPTO_ADDRESS_SCHEME_BTC_LEGACY)
#if HAS_BCH_TESTNET
DEFINE_MODES            ("bitcoincash-testnet", CRYPTO_SYNC_MODE_API_ONLY,  CRYPTO_SYNC_MODE_P2P_ONLY)
#else
DEFINE_MODES            ("bitcoincash-testnet", CRYPTO_SYNC_MODE_P2P_ONLY)
#endif
#undef NETWORK_NAME

// MARK: - BSV

#define NETWORK_NAME    "Bitcoin SV"
DEFINE_NETWORK (CRYPTO_NETWORK_TYPE_BSV,  "bitcoinsv-mainnet", NETWORK_NAME, "mainnet", true, 672728, 6, 10 * 60)
DEFINE_NETWORK_FEE_ESTIMATE ("bitcoinsv-mainnet", "2", "10m", 20 * 60 * 1000)
DEFINE_CURRENCY ("bitcoinsv-mainnet",     "bitcoinsv-mainnet:__native__",   NETWORK_NAME,  CRYPTO_NETWORK_CURRENCY_BSV,  "native",   NULL,   true)
    DEFINE_UNIT ("bitcoinsv-mainnet:__native__",      "Satoshi",    "sat",      0,      "SAT")
    DEFINE_UNIT ("bitcoinsv-mainnet:__native__",      NETWORK_NAME, "bsv",      8,      "BSV")
DEFINE_ADDRESS_SCHEMES  ("bitcoinsv-mainnet", CRYPTO_ADDRESS_SCHEME_BTC_LEGACY)
DEFINE_MODES            ("bitcoinsv-mainnet", CRYPTO_SYNC_MODE_API_ONLY, CRYPTO_SYNC_MODE_P2P_ONLY)

DEFINE_NETWORK (CRYPTO_NETWORK_TYPE_BSV,  "bitcoinsv-testnet", NETWORK_NAME, "testnet", false, 528135, 6, 10 * 60)
DEFINE_NETWORK_FEE_ESTIMATE ("bitcoinsv-testnet", "2", "10m", 20 * 60 * 1000)
DEFINE_CURRENCY ("bitcoinsv-testnet",     "bitcoinsv-testnet:__native__",   NETWORK_NAME,  CRYPTO_NETWORK_CURRENCY_BSV,  "native",   NULL,   true)
    DEFINE_UNIT ("bitcoinsv-testnet:__native__",      "Satoshi",    "sat",      0,      "SAT")
    DEFINE_UNIT ("bitcoinsv-testnet:__native__",      NETWORK_NAME, "bsv",      8,      "BSV")
DEFINE_ADDRESS_SCHEMES  ("bitcoinsv-testnet", CRYPTO_ADDRESS_SCHEME_BTC_LEGACY)
#if HAS_BSV_TESTNET
DEFINE_MODES            ("bitcoinsv-testnet", CRYPTO_SYNC_MODE_API_ONLY,  CRYPTO_SYNC_MODE_P2P_ONLY)
#else
DEFINE_MODES            ("bitcoinsv-testnet", CRYPTO_SYNC_MODE_P2P_ONLY)
#endif
#undef NETWORK_NAME

// MARK: - LTC

#define NETWORK_NAME    "Litecoin"
DEFINE_NETWORK (CRYPTO_NETWORK_TYPE_LTC,  "litecoin-mainnet", NETWORK_NAME, "mainnet", true, 2056308, 12, (5*60)/2)  // 2.5 min
DEFINE_NETWORK_FEE_ESTIMATE ("litecoin-mainnet", "2", "5m", 5 * 60 * 1000)
DEFINE_CURRENCY ("litecoin-mainnet",     "litecoin-mainnet:__native__",   NETWORK_NAME,  CRYPTO_NETWORK_CURRENCY_LTC,  "native",   NULL,   true)
    DEFINE_UNIT ("litecoin-mainnet:__native__",      "Satoshi",    "sat",      0,      "SAT")
    DEFINE_UNIT ("litecoin-mainnet:__native__",      NETWORK_NAME, "ltc",      8,      "LTC")
DEFINE_ADDRESS_SCHEMES  ("litecoin-mainnet", CRYPTO_ADDRESS_SCHEME_BTC_SEGWIT, CRYPTO_ADDRESS_SCHEME_BTC_LEGACY)
DEFINE_MODES            ("litecoin-mainnet", CRYPTO_SYNC_MODE_API_ONLY, CRYPTO_SYNC_MODE_P2P_ONLY)

DEFINE_NETWORK (CRYPTO_NETWORK_TYPE_LTC,  "litecoin-testnet", NETWORK_NAME, "testnet", false, 1903181, 12, (5*60)/2)  // 2.5 min
DEFINE_NETWORK_FEE_ESTIMATE ("litecoin-testnet", "2", "5m", 5 * 60 * 1000)
DEFINE_CURRENCY ("litecoin-testnet",     "litecoin-testnet:__native__",   NETWORK_NAME,  CRYPTO_NETWORK_CURRENCY_LTC,  "native",   NULL,   true)
    DEFINE_UNIT ("litecoin-testnet:__native__",      "Satoshi",    "sat",      0,      "SAT")
    DEFINE_UNIT ("litecoin-testnet:__native__",      NETWORK_NAME, "ltc",      8,      "LTC")
DEFINE_ADDRESS_SCHEMES  ("litecoin-testnet", CRYPTO_ADDRESS_SCHEME_BTC_SEGWIT, CRYPTO_ADDRESS_SCHEME_BTC_LEGACY)
#if HAS_LTC_TESTNET
DEFINE_MODES            ("litecoin-testnet", CRYPTO_SYNC_MODE_API_ONLY,  CRYPTO_SYNC_MODE_P2P_ONLY)
#else
DEFINE_MODES            ("litecoin-testnet", CRYPTO_SYNC_MODE_P2P_ONLY)
#endif
//DEFINE_HANDLERS (CRYPTO_NETWORK_TYPE_LTC, LTC)
#undef NETWORK_NAME

// MARK: - ETH

#define NETWORK_NAME    "Ethereum"
DEFINE_NETWORK (CRYPTO_NETWORK_TYPE_ETH,  "ethereum-mainnet", NETWORK_NAME, "mainnet", true, 11779945, 6, 10 * 60)
DEFINE_NETWORK_FEE_ESTIMATE ("ethereum-mainnet", "25000000000", "1m", 1 * 60 * 1000)
DEFINE_CURRENCY ("ethereum-mainnet",     "ethereum-mainnet:__native__",   NETWORK_NAME,  CRYPTO_NETWORK_CURRENCY_ETH,  "native",   NULL,   true)
    DEFINE_UNIT ("ethereum-mainnet:__native__",      "Wei",         "wei",      0,      "WEI")
    DEFINE_UNIT ("ethereum-mainnet:__native__",      "Gwei",        "gwei",     9,      "GWEI")
    DEFINE_UNIT ("ethereum-mainnet:__native__",      "Ether",       "eth",     18,      "Ξ")

// Tether USD
DEFINE_CURRENCY ("ethereum-mainnet",    "ethereum-mainnet:0xdac17f958d2ee523a2206206994597c13d831ec7",  "Tether USD",    "usdt",  "erc20",   "0xdac17f958d2ee523a2206206994597c13d831ec7",   true)
DEFINE_UNIT ("ethereum-mainnet:0xdac17f958d2ee523a2206206994597c13d831ec7",      "Tether USD Int",             "usdti",       0,     "USDTI")
DEFINE_UNIT ("ethereum-mainnet:0xdac17f958d2ee523a2206206994597c13d831ec7",      "Tether USD",             "usdt",       6,     "USDT")

// Shiba Inu
DEFINE_CURRENCY ("ethereum-mainnet",    "ethereum-mainnet:0x95aD61b0a150d79219dCF64E1E6Cc01f0B64C4cE",  "Shiba Inu",    "shib",  "erc20",   "0x95aD61b0a150d79219dCF64E1E6Cc01f0B64C4cE",   true)
DEFINE_UNIT ("ethereum-mainnet:0x95aD61b0a150d79219dCF64E1E6Cc01f0B64C4cE",      "Shiba Inu Int",             "shibi",       0,     "SHIBI")
DEFINE_UNIT ("ethereum-mainnet:0x95aD61b0a150d79219dCF64E1E6Cc01f0B64C4cE",      "Shiba Inu",             "shib",       18,     "SHIB")

// Basic Attention
DEFINE_CURRENCY ("ethereum-mainnet",    "ethereum-mainnet:0x0D8775F648430679A709E98d2b0Cb6250d2887EF",  "Basic Attention",    "bat",  "erc20",   "0x0D8775F648430679A709E98d2b0Cb6250d2887EF",   true)
DEFINE_UNIT ("ethereum-mainnet:0x0D8775F648430679A709E98d2b0Cb6250d2887EF",      "Basic Attention Int",             "bati",       0,     "BATI")
DEFINE_UNIT ("ethereum-mainnet:0x0D8775F648430679A709E98d2b0Cb6250d2887EF",      "Basic Attention",             "bat",       18,     "BAT")

// ChainLink
DEFINE_CURRENCY ("ethereum-mainnet",    "ethereum-mainnet:0x514910771af9ca656af840dff83e8264ecf986ca",  "ChainLink",    "link",  "erc20",   "0x514910771af9ca656af840dff83e8264ecf986ca",   true)
DEFINE_UNIT ("ethereum-mainnet:0x514910771af9ca656af840dff83e8264ecf986ca",      "ChainLink Int",             "linki",       0,     "LINKI")
DEFINE_UNIT ("ethereum-mainnet:0x514910771af9ca656af840dff83e8264ecf986ca",      "ChainLink",             "link",       18,     "LINK")

// Loopring
DEFINE_CURRENCY ("ethereum-mainnet",    "ethereum-mainnet:0xbbbbca6a901c926f240b89eacb641d8aec7aeafd",  "Loopring",    "lrc",  "erc20",   "0xbbbbca6a901c926f240b89eacb641d8aec7aeafd",   true)
DEFINE_UNIT ("ethereum-mainnet:0xbbbbca6a901c926f240b89eacb641d8aec7aeafd",      "Loopring Int",             "lrci",       0,     "LRCI")
DEFINE_UNIT ("ethereum-mainnet:0xbbbbca6a901c926f240b89eacb641d8aec7aeafd",      "Loopring",             "lrc",       18,     "LRC")

// 0x
DEFINE_CURRENCY ("ethereum-mainnet",    "ethereum-mainnet:0xE41d2489571d322189246DaFA5ebDe1F4699F498",  "0x",    "zrx",  "erc20",   "0xE41d2489571d322189246DaFA5ebDe1F4699F498",   true)
DEFINE_UNIT ("ethereum-mainnet:0xE41d2489571d322189246DaFA5ebDe1F4699F498",      "0x Int",             "zrxi",       0,     "ZRXI")
DEFINE_UNIT ("ethereum-mainnet:0xE41d2489571d322189246DaFA5ebDe1F4699F498",      "0x",             "zrx",       18,     "ZRX")

// BRD
DEFINE_CURRENCY ("ethereum-mainnet",    "ethereum-mainnet:0x558ec3152e2eb2174905cd19aea4e34a23de9ad6",  "BRD Token",    "brd",  "erc20",   "0x558ec3152e2eb2174905cd19aea4e34a23de9ad6",   true)
DEFINE_UNIT ("ethereum-mainnet:0x558ec3152e2eb2174905cd19aea4e34a23de9ad6",      "BRD Token Int",             "brdi",       0,     "BRDI")
DEFINE_UNIT ("ethereum-mainnet:0x558ec3152e2eb2174905cd19aea4e34a23de9ad6",      "BRD Token",             "brd",       18,     "BRD")

// USDC
DEFINE_CURRENCY ("ethereum-mainnet",    "ethereum-mainnet:0xA0b86991c6218b36c1d19D4a2e9Eb0cE3606eB48",  "USD Coin",    "usdc",  "erc20",   "0xA0b86991c6218b36c1d19D4a2e9Eb0cE3606eB48",   true)
DEFINE_UNIT ("ethereum-mainnet:0xA0b86991c6218b36c1d19D4a2e9Eb0cE3606eB48",      "USD Coin Int",             "usdci",       0,     "USDCI")
DEFINE_UNIT ("ethereum-mainnet:0xA0b86991c6218b36c1d19D4a2e9Eb0cE3606eB48",      "USD Coin",             "usdc",       6,     "USDC")

DEFINE_ADDRESS_SCHEMES  ("ethereum-mainnet", CRYPTO_ADDRESS_SCHEME_NATIVE)
DEFINE_MODES            ("ethereum-mainnet", CRYPTO_SYNC_MODE_API_ONLY)

#if HAS_ETH_TESTNET
DEFINE_NETWORK (CRYPTO_NETWORK_TYPE_ETH,  "ethereum-goerli", NETWORK_NAME, "testnet", false, 9588166, 6, 10 * 60)
DEFINE_NETWORK_FEE_ESTIMATE ("ethereum-goerli", "10000000000", "1m", 1 * 60 * 1000)
DEFINE_CURRENCY ("ethereum-goerli",     "ethereum-goerli:__native__",   NETWORK_NAME,  CRYPTO_NETWORK_CURRENCY_ETH,  "native",   NULL,   true)
    DEFINE_UNIT ("ethereum-goerli:__native__",      "Wei",         "wei",      0,      "WEI")
    DEFINE_UNIT ("ethereum-goerli:__native__",      "Gwei",        "gwei",     9,      "GWEI")
    DEFINE_UNIT ("ethereum-goerli:__native__",      "Ether",       "eth",     18,      "Ξ")
DEFINE_CURRENCY ("ethereum-goerli",    "ethereum-goerli:0x509ee0d083ddf8ac028f2a56731412edd63223b9",  "Tether USD",    "usdt",  "erc20",   "0x509ee0d083ddf8ac028f2a56731412edd63223b9",   true)
DEFINE_UNIT ("ethereum-goerli:0x509ee0d083ddf8ac028f2a56731412edd63223b9",      "Tether USD Int",             "usdti",       0,     "USDTI")
DEFINE_UNIT ("ethereum-goerli:0x509ee0d083ddf8ac028f2a56731412edd63223b9",      "Tether USD",             "usdt",       6,     "USDT")
DEFINE_CURRENCY ("ethereum-goerli",    "ethereum-goerli:0x326c977e6efc84e512bb9c30f76e30c160ed06fb",  "ChainLink Token",    "link",  "erc20",   "0x326c977e6efc84e512bb9c30f76e30c160ed06fb",   true)
DEFINE_UNIT ("ethereum-goerli:0x326c977e6efc84e512bb9c30f76e30c160ed06fb",      "ChainLink Token Int",             "linki",       0,     "LINKI")
DEFINE_UNIT ("ethereum-goerli:0x326c977e6efc84e512bb9c30f76e30c160ed06fb",      "ChainLink Token",             "link",       18,     "LINK")
DEFINE_ADDRESS_SCHEMES  ("ethereum-goerli", CRYPTO_ADDRESS_SCHEME_NATIVE)
DEFINE_MODES            ("ethereum-goerli", CRYPTO_SYNC_MODE_API_ONLY)
#endif
#undef NETWORK_NAME

// MARK: XRP

#define NETWORK_NAME    "Ripple"
DEFINE_NETWORK (CRYPTO_NETWORK_TYPE_XRP,  "ripple-mainnet", NETWORK_NAME, "mainnet", true, 61321875, 1, 10 * 60)
DEFINE_NETWORK_FEE_ESTIMATE ("ripple-mainnet", "10", "1m", 1 * 60 * 1000)
DEFINE_CURRENCY ("ripple-mainnet",     "ripple-mainnet:__native__",   NETWORK_NAME,  CRYPTO_NETWORK_CURRENCY_XRP,  "native",   NULL,   true)
    DEFINE_UNIT ("ripple-mainnet:__native__",      "Drop",       "drop",      0,      "DROP")
    DEFINE_UNIT ("ripple-mainnet:__native__",      NETWORK_NAME, "xrp",       6,      "XRP")
DEFINE_ADDRESS_SCHEMES  ("ripple-mainnet", CRYPTO_ADDRESS_SCHEME_NATIVE)
DEFINE_MODES            ("ripple-mainnet", CRYPTO_SYNC_MODE_API_ONLY)

#if HAS_XRP_TESTNET
DEFINE_NETWORK (CRYPTO_NETWORK_TYPE_XRP,  "ripple-testnet", NETWORK_NAME, "testnet", false, 50000, 1, 10 * 60)
DEFINE_NETWORK_FEE_ESTIMATE ("ripple-testnet", "10", "1m", 1 * 60 * 1000)
DEFINE_CURRENCY ("ripple-testnet",     "ripple-testnet:__native__",   NETWORK_NAME,  CRYPTO_NETWORK_CURRENCY_XRP,  "native",   NULL,   true)
    DEFINE_UNIT ("ripple-testnet:__native__",      "Drop",       "drop",      0,      "DROP")
    DEFINE_UNIT ("ripple-testnet:__native__",      NETWORK_NAME, "xrp",       6,      "XRP")
DEFINE_ADDRESS_SCHEMES  ("ripple-testnet", CRYPTO_ADDRESS_SCHEME_NATIVE)
DEFINE_MODES            ("ripple-testnet", CRYPTO_SYNC_MODE_API_ONLY)
#endif
#undef NETWORK_NAME

// MARK: HBAR

#define NETWORK_NAME    "Hedera"
DEFINE_NETWORK (CRYPTO_NETWORK_TYPE_HBAR,  "hedera-mainnet", NETWORK_NAME, "mainnet", true, 12295580, 1, 10 * 60)
DEFINE_NETWORK_FEE_ESTIMATE ("hedera-mainnet", "500000", "1m", 1 * 60 * 1000)
DEFINE_CURRENCY ("hedera-mainnet",     "hedera-mainnet:__native__",   NETWORK_NAME,  CRYPTO_NETWORK_CURRENCY_HBAR,  "native",   NULL,   true)
    DEFINE_UNIT ("hedera-mainnet:__native__",  "tinybar",     "thbar",  0,  "tℏ")
    DEFINE_UNIT ("hedera-mainnet:__native__",  NETWORK_NAME,  "hbar",   8,  "ℏ")
DEFINE_ADDRESS_SCHEMES  ("hedera-mainnet", CRYPTO_ADDRESS_SCHEME_NATIVE)
DEFINE_MODES            ("hedera-mainnet", CRYPTO_SYNC_MODE_API_ONLY)

#if HAS_HBAR_TESTNET
DEFINE_NETWORK (CRYPTO_NETWORK_TYPE_HBAR,  "hedera-testnet", NETWORK_NAME, "testnet", false, 50000, 1, 10 * 60)
DEFINE_NETWORK_FEE_ESTIMATE ("hedera-testnet", "500000", "1m", 1 * 60 * 1000)
DEFINE_CURRENCY ("hedera-testnet",     "hedera-testnet:__native__",   NETWORK_NAME,  CRYPTO_NETWORK_CURRENCY_HBAR,  "native",   NULL,   true)
    DEFINE_UNIT ("hedera-testnet:__native__",  "tinybar",     "thbar",  0,  "tℏ")
    DEFINE_UNIT ("hedera-testnet:__native__",  NETWORK_NAME,  "hbar",   8,  "ℏ")
DEFINE_ADDRESS_SCHEMES  ("hedera-testnet", CRYPTO_ADDRESS_SCHEME_NATIVE)
DEFINE_MODES            ("hedera-testnet", CRYPTO_SYNC_MODE_API_ONLY)
#endif
#undef NETWORK_NAME

// MARK: Tezos

#define NETWORK_NAME    "Tezos"
DEFINE_NETWORK (CRYPTO_NETWORK_TYPE_XTZ,  "tezos-mainnet", NETWORK_NAME, "mainnet", true, 1328407, 6, 10 * 60)
DEFINE_NETWORK_FEE_ESTIMATE ("tezos-mainnet", "500000", "1m", 1 * 60 * 1000)
DEFINE_CURRENCY ("tezos-mainnet",     "tezos-mainnet:__native__",   NETWORK_NAME,  CRYPTO_NETWORK_CURRENCY_XTZ,  "native",   NULL,   true)
    DEFINE_UNIT ("tezos-mainnet:__native__",  "mutez",     "mtz",   0,  "mutez")
    DEFINE_UNIT ("tezos-mainnet:__native__",  NETWORK_NAME,  "xtz",   6,  "XTZ")
DEFINE_ADDRESS_SCHEMES  ("tezos-mainnet", CRYPTO_ADDRESS_SCHEME_NATIVE)
DEFINE_MODES            ("tezos-mainnet", CRYPTO_SYNC_MODE_API_ONLY)

#if HAS_XTZ_TESTNET
DEFINE_NETWORK (CRYPTO_NETWORK_TYPE_XTZ,  "tezos-testnet", NETWORK_NAME, "testnet", false, 50000, 6, 10 * 60)
DEFINE_NETWORK_FEE_ESTIMATE ("tezos-testnet", "500000", "1m", 1 * 60 * 1000)
DEFINE_CURRENCY ("tezos-testnet",     "tezos-testnet:__native__",   NETWORK_NAME,  CRYPTO_NETWORK_CURRENCY_XTZ,  "native",   NULL,   true)
    DEFINE_UNIT ("tezos-testnet:__native__",  "mutez",     "mtz",   0,  "mutez")
    DEFINE_UNIT ("tezos-testnet:__native__",  NETWORK_NAME,  "xtz",   6,  "XTZ")
DEFINE_ADDRESS_SCHEMES  ("tezos-testnet", CRYPTO_ADDRESS_SCHEME_NATIVE)
DEFINE_MODES            ("tezos-testnet", CRYPTO_SYNC_MODE_API_ONLY)
#endif
#undef NETWORK_NAME

// MARK: XLM Mainnet

#undef DEFINE_NETWORK
#undef DEFINE_NETWORK_FEE_ESTIMATE
#undef DEFINE_CURRENCY
#undef DEFINE_UNIT
#undef DEFINE_ADDRESS_SCHEMES
#undef DEFINE_MODES
