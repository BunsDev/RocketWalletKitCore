//
//  WKClient.h
//  WK
//
//  Created by Michael Carrara on 6/19/19.
//  Copyright © 2019 breadwallet. All rights reserved.
//
//  See the LICENSE file at the project root for license information.
//  See the CONTRIBUTORS file at the project root for a list of contributors.

#ifndef WKClient_h
#define WKClient_h

#include "WKBase.h"
#include "WKTransfer.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void *WKClientContext;

typedef struct WKClientCallbackStateRecord *WKClientCallbackState;

// MARK: - Get Block Number

typedef void
(*WKClientGetBlockNumberCallback) (WKClientContext context,
                                         OwnershipGiven WKWalletManager manager,
                                         OwnershipGiven WKClientCallbackState callbackState);

extern void
wkClientAnnounceBlockNumber (OwnershipKept WKWalletManager cwm,
                               OwnershipGiven WKClientCallbackState callbackState,
                               WKBoolean success,
                               WKBlockNumber blockNumber,
                               const char *verifiedBlockHash);

// MARK: - Get Transactions

typedef void
(*WKClientGetTransactionsCallback) (WKClientContext context,
                                          OwnershipGiven WKWalletManager manager,
                                          OwnershipGiven WKClientCallbackState callbackState,
                                          OwnershipKept const char **addresses,
                                          size_t addressCount,
                                          WKBlockNumber begBlockNumber,
                                          WKBlockNumber endBlockNumber);

typedef struct WKClientTransactionBundleRecord *WKClientTransactionBundle;

extern WKClientTransactionBundle
wkClientTransactionBundleCreate (WKTransferStateType status,
                                     OwnershipKept uint8_t *transaction,
                                     size_t transactionLength,
                                     WKTimestamp timestamp,
                                     WKBlockNumber blockHeight);

extern void
wkClientTransactionBundleRelease (WKClientTransactionBundle bundle);

// b1 < b2 => -1; b1 > b2 => +1, b1 == b2 => 0
extern int
wkClientTransactionBundleCompare (const WKClientTransactionBundle b1,
                                      const WKClientTransactionBundle b2);

static inline int
wkClientTransactionBundleCompareForSort (const void *v1, const void *v2) {
    const WKClientTransactionBundle *b1 = v1;
    const WKClientTransactionBundle *b2 = v2;
    return wkClientTransactionBundleCompare (*b1, *b2);
}

static inline int
wkClientTransactionBundleCompareByBlockheightForSort (const void *tb1, const void *tb2) {
    WKClientTransactionBundle b1 = * (WKClientTransactionBundle *) tb1;
    WKClientTransactionBundle b2 = * (WKClientTransactionBundle *) tb2;
    return wkClientTransactionBundleCompare (b1, b2);
}

extern void
wkClientAnnounceTransactions (OwnershipKept WKWalletManager cwm,
                                  OwnershipGiven WKClientCallbackState callbackState,
                                  WKBoolean success,
                                  WKClientTransactionBundle *bundles,
                                  size_t bundlesCount);

// MARK: - Get Transfers

typedef void
(*WKClientGetTransfersCallback) (WKClientContext context,
                                       OwnershipGiven WKWalletManager manager,
                                       OwnershipGiven WKClientCallbackState callbackState,
                                       OwnershipKept const char **addresses,
                                       size_t addressCount,
                                       WKBlockNumber begBlockNumber,
                                       WKBlockNumber endBlockNumber);

typedef struct WKClientTransferBundleRecord *WKClientTransferBundle;

extern WKClientTransferBundle
wkClientTransferBundleCreate (WKTransferStateType status,
                                  OwnershipKept const char *uids,
                                  OwnershipKept const char *hash,
                                  OwnershipKept const char *identifier,
                                  OwnershipKept const char *from,
                                  OwnershipKept const char *to,
                                  OwnershipKept const char *amount,
                                  OwnershipKept const char *currency,
                                  OwnershipKept const char *fee,
                                  WKTimestamp blockTimestamp,
                                  WKBlockNumber blockNumber,
                                  WKBlockNumber blockConfirmations,
                                  uint64_t blockTransactionIndex,
                                  OwnershipKept const char *blockHash,
                                  size_t attributesCount,
                                  OwnershipKept const char **attributeKeys,
                                  OwnershipKept const char **attributeVals);

extern void
wkClientTransferBundleRelease (WKClientTransferBundle bundle);

extern int
wkClientTransferBundleCompare (const WKClientTransferBundle b1,
                                   const WKClientTransferBundle b2);

static inline int
wkClientTransferBundleCompareForSort (const void *v1, const void *v2) {
    const WKClientTransferBundle *b1 = v1;
    const WKClientTransferBundle *b2 = v2;
    return wkClientTransferBundleCompare (*b1, *b2);
}

extern int
wkClientTransferBundleCompareByBlockheight (const WKClientTransferBundle b1,
                                                const WKClientTransferBundle b2);

static inline int
wkClientTransferBundleCompareByBlockheightForSort (const void *tb1, const void *tb2) {
    WKClientTransferBundle b1 = * (WKClientTransferBundle *) tb1;
    WKClientTransferBundle b2 = * (WKClientTransferBundle *) tb2;
    return wkClientTransferBundleCompareByBlockheight (b1, b2);
}

extern WKTransferState
wkClientTransferBundleGetTransferState (const WKClientTransferBundle bundle,
                                            WKFeeBasis confirmedFeeBasis);

extern void
wkClientAnnounceTransfers (OwnershipKept WKWalletManager cwm,
                               OwnershipGiven WKClientCallbackState callbackState,
                               WKBoolean success,
                               WKClientTransferBundle *bundles,
                               size_t bundlesCount);

// MARK: - Submit Transaction

typedef void
(*WKClientSubmitTransactionCallback) (WKClientContext context,
                                            OwnershipGiven WKWalletManager manager,
                                            OwnershipGiven WKClientCallbackState callbackState,
                                            OwnershipKept const char    *identifier,
                                            OwnershipKept const char    *exchangeId,
                                            OwnershipKept const uint8_t *transaction,
                                            size_t transactionLength);

extern void
wkClientAnnounceSubmitTransfer (OwnershipKept WKWalletManager cwm,
                                    OwnershipGiven WKClientCallbackState callbackState,
                                    OwnershipKept const char *identifier,
                                    OwnershipKept const char *hash,
                                    WKBoolean success);

// MARK: - Estimate Transaction Fee

typedef void
(*WKClientEstimateTransactionFeeCallback) (WKClientContext context,
                                                 OwnershipGiven WKWalletManager manager,
                                                 OwnershipGiven WKClientCallbackState callbackState,
                                                 OwnershipKept const uint8_t *transaction,
                                                 size_t transactionLength,
                                                 OwnershipKept const char *hashAsHex);

extern void
wkClientAnnounceEstimateTransactionFee (OwnershipKept WKWalletManager cwm,
                                            OwnershipGiven WKClientCallbackState callbackState,
                                            WKBoolean success,
                                            uint64_t costUnits,
                                            size_t attributesCount,
                                            OwnershipKept const char **attributeKeys,
                                            OwnershipKept const char **attributeVals);

// MARK: - Currency

typedef struct WKClientCurrencyBundleRecord *WKClientCurrencyBundle;
typedef struct WKCliehtCurrencyDenominationBundleRecord *WKClientCurrencyDenominationBundle;

extern WKClientCurrencyDenominationBundle
wkClientCurrencyDenominationBundleCreate (const char *name,
                                              const char *code,
                                              const char *symbol,
                                              uint8_t     decimals);

extern WKClientCurrencyBundle
wkClientCurrencyBundleCreate (const char *id,
                                  const char *name,
                                  const char *code,
                                  const char *type,
                                  const char *blockchainId,
                                  const char *address,
                                  bool verified,
                                  size_t denominationsCount,
                                  WKClientCurrencyDenominationBundle *denominations);

extern void
wkClientCurrencyBundleRelease (WKClientCurrencyBundle bundle);

extern void
wkClientAnnounceCurrencies (WKSystem system,
                                OwnershipGiven WKClientCurrencyBundle *bundles,
                                size_t bundlesCount);

typedef struct {
    WKClientContext context;
    WKClientGetBlockNumberCallback  funcGetBlockNumber;
    WKClientGetTransactionsCallback funcGetTransactions;
    WKClientGetTransfersCallback funcGetTransfers;
    WKClientSubmitTransactionCallback funcSubmitTransaction;
    WKClientEstimateTransactionFeeCallback funcEstimateTransactionFee;
} WKClient;

#ifdef __cplusplus
}
#endif

#endif /* WKClient_h */
