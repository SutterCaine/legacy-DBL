// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"

#include "random.h"
#include "util.h"
#include "utilstrencodings.h"

#include <assert.h>

#include <boost/assign/list_of.hpp>

using namespace std;
using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

/**
 * Main network
 */

//! Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress> &vSeedsOut, const SeedSpec6 *data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7*24*60*60;
    for (unsigned int i = 0; i < count; i++)
    {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

/**
 * What makes a good checkpoint block?
 * + Is surrounded by blocks with reasonable timestamps
 *   (no blocks before with a timestamp after, none after with
 *    timestamp before)
 * + Contains no strange transactions
 */
static Checkpoints::MapCheckpoints mapCheckpoints =
        boost::assign::map_list_of
        (         0, uint256("0xbbd01e417e370842498a91038fd40da95f4a6166a231a3bed3c4671207bd8296"))
        (        25, uint256("0x52424ba26dd18c2da10170054c8c39ec649d0ac2630585e53099ac70dc360721"))
        (       125, uint256("0xa13b9e454a00927f6b6fd59eda118d76b270f09f80ff848e7f3cb9a2f47837ed"))
        (      1025, uint256("0xa59d07caeca8b8601803a72729dabb846e4a2adda0022ea212e4911824ff85ae"))
        (      5025, uint256("0xdc5ea38e4b4f68e66ec4fe3c7b742f02388bca5d90f3c340675229f8ae23f8ca"))
        (     10025, uint256("0x5fac2e11b6ab636534d0dc557f86f302b71647c9084eae6fe2ca389a37bb4e68"))
        (     11025, uint256("0xb68d83930c52a880326fdda93fa6963e95133c1592cab5c8488b8aaebb4206b3"))
        (     13025, uint256("0x5d5eb98932c5d81a1bac5fc653c2d95e648d089b2a607ca6ac15975bf05af009"))
        (     15025, uint256("0x2c4305a5e070e1f470fa3289653db98bd7dd6eb847780d6d32e65d5b901b429f"))
        (     20025, uint256("0x38d3027035e4725852203ee4a38768ce3fd12cc8d3d9ee1c00467d17d81c42be"))
        (     25025, uint256("0x005df538003a40bc5f83c299397dce6a4d2a736ab4fdf46752a8fcec5a45cf7f"))
        (     30025, uint256("0x0c3a6a48a8811b9c1683d86148b40384e0920a4020e0229bb7d3928e4c1e3168"))
        (     35000, uint256("0xbc86cab2bf3c1dba06e511b7a0830dd1252b5b860cae1ae90c61c0ff117d191a"))
        (     40025, uint256("0xafc48c6b0414bdc09ab31033ed4dd56d76c3fb29bc775060f2e393d58683625a"))
        (     43665, uint256("0xa77dbe7205f122896e3f172a0fc7e99d662cf15cf4e92324cbf69a472160a1bd"))
        (     43869, uint256("0xa55c9f9c892dc84fc97a670e79d79c3bec8f9dd9e32647fae8d8dcf13351f395"))
        (     46132, uint256("0xcab3584e46e2b038475cee3fc151930a5254989973509463cd9ad5980525c59a"))
        (     46525, uint256("0x80f62adfbb336b80c66a2eea963a705696f83787f375d72454511cef6db9ae77"))
        (     47025, uint256("0x16d4d4462499ade6076ef2996913eb4b91eb6965e9d78b2553a83974ae42b57f"))
        (     47525, uint256("0xa881a1f71726e1606211db240ea34f06343418a60739ce53195ddabee302b5de"))
        (     48025, uint256("0xb63b43ed40ab1aaec59228dcc11259a8bc1407b20257fd1283d74bc60501a158"))
        (     48525, uint256("0xe7754742b376b32a816038256f5277fa073527b6526887484ecbd8439b22eecf"))
        (     49025, uint256("0xef808fbbf7d5588394164b9f6c4190ae895134f1aa0d220f6379394e97ec07d7"))
        (     50025, uint256("0x71c30991bff5baeefb2b6d976f9e54c72a25f164c14fe2239b5de248392f9d80"))
        (     60025, uint256("0x9d7095a313497f158b65a7832e1434d06a52d76799b4d7c6db6a7f966b488013"))
        (     65025, uint256("0x6fa8c8e1980d9929b09e0d8a2536c0fe67f230b02923060ab013d459c2c17184"))
        (     65525, uint256("0xebf93cdd64236622786e8b2b55079f70db658c6b27eccd92574271507789633e"))
        (     85525, uint256("0x482eab083d59ff7846dbeedadd5bffbe31737a9ce703d39e35bb39a17982be25"))
        (     95525, uint256("0xe66cb922df396e62026b2c2c812690ce962bd3ad2a1e70b6d2f8b60732a9978b"))
        (    105525, uint256("0x2ac38e841ca3b8362aa3a7bbf3e757055518a450ce4712c73124be161a03ccc2"))
        (    110000, uint256("0xe2d99af9501e8c2af2cce48516b925ac37c60b479530c72c7f9d198f7ee6fa07"))
        (    120000, uint256("0x931dc828b580cbafe526c7db7e21fe807cba4fd7c0827e56dcf297267db13ba5"))
        (    130000, uint256("0x4ec7cc6e98f87690f90969ff85e2fa133238cb4e80766c0b64796fce5317a902"))
        (    140000, uint256("0xfcfd03560902a1b0ae6ba0de86a0992182600d57825b7a9e301fcca77e434c2c"))
        (    267269, uint256("0x896b0ce91d5d7b3512871444a05f53d34c4c0e6c338b1c6de0e6c92aa10debb9"))
        (    267270, uint256("0x595e91d2ab47f6313c48802a8befce80d83757c095350b1f3b0ce7127fe2b0f6"))
        (    300000, uint256("0xd9941fe7230bb38099fb8bfab31bfa0d54b4806e4f1b4900a3403297e5bc4a1c"))
        (    324000, uint256("0x0e57d704b97c43a97031161604412fd312e4b7de9650e8d85b5b9a4a041d8a80"))
        (    532300, uint256("0xdc86594eb869ad0038ccd0d81fc663011ee58a6532cdceaaa9094f2d8bd49e93"))
	(    764000, uint256("0xb0ef75e47bea4688bc5074cce4689a58c5961c48cd0618a78e9b436423f96433"))
        ;
static const Checkpoints::CCheckpointData data = {
        &mapCheckpoints,
        1432553242, // * UNIX timestamp of last checkpoint block
        816435,   // * total number of transactions between genesis and last checkpoint
                    //   (the tx=... number in the SetBestChain debug.log lines)
        500.0     // * estimated number of transactions per day after checkpoint
    };

//need be removed - no testned data for doubloons!
static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
        boost::assign::map_list_of
        ( 546, uint256("0xa0fea99a6897f531600c8ae53367b126824fd6a847b2b2b73817a95b8e27e602"))
        ;
static const Checkpoints::CCheckpointData dataTestnet = {
        &mapCheckpointsTestnet,
        1365458829,
        547,
        576
    };

static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
        boost::assign::map_list_of
        ( 0, uint256("0f9188f13cb7b2c71f2a335e3a4fc328bf5beb436012afca590b1a11466e2206"))
        ;
static const Checkpoints::CCheckpointData dataRegtest = {
        &mapCheckpointsRegtest,
        0,
        0,
        0
    };

class CMainParams : public CChainParams {
public:
    CMainParams() {
        networkID = CBaseChainParams::MAIN;
        strNetworkID = "main";
        /** 
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */
        pchMessageStart[0] = 0xfc;
        pchMessageStart[1] = 0xd9;
        pchMessageStart[2] = 0xb7; //dbl
        pchMessageStart[3] = 0xdd;
        vAlertPubKey = ParseHex("040184710fa689ad5023690c80f3a49c8f13f8d45b8c857fbcbc8bc4a8e4d3eb4b10f4d4604fa08dce601aaf0f470216fe1b51850b4acf21b179c45070ac7b03a9");//ltc
        nDefaultPort = 1336;
        bnProofOfWorkLimit = ~uint256(0) >> 20;
        nSubsidyHalvingInterval = 10519200; //DBL - it will be 0 after that
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 0;
        nTargetTimespan =  0.5 * 24 * 60 * 60; // Doubloons: 43,200 seconds (12 hours)
        nTargetSpacing = 60; // DBL: 1 minute

        /**
         * Build the genesis block. Note that the output of the genesis coinbase cannot
         * be spent as it did not originally exist in the database.
    // Genesis block:
    // block.nTime = 1366559428 
    // block.nNonce = 2085386442 
    // block.GetHash = 384b060671f4a93948e9c168216dadb0ca2fbc54aa11c86b0345b6af1c59b2f5
    // CBlock(hash=384b060671f4a93948e9, PoW=00000951e146b0026411, ver=1,
    //  hashPrevBlock=00000000000000000000, hashMerkleRoot=5a2e19825b,
    //  nTime=1366559428, nBits=1e0ffff0, nNonce=2085386442, vtx=1)
    // CTransaction(hash=5a2e19825b, ver=1, vin.size=1, vout.size=1, nLockTime=0)
    // CTxIn(COutPoint(0000000000, -1), coinbase 04ffff001d010441746f646f3a207265706c616365207769746820736f6d657468696e67207468617420656e7375726573206e6f207072656d696e696e6720746f6f6b20706c616365)
    // CTxOut(error)
    // vMerkleTree: 5a2e19825b
     */
        const char* pszTimestamp = "Man-defined-as-top-US-pirate-catch-appeals-in-Va - 5.14.2013";
        CMutableTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 0;
        txNew.vout[0].scriptPubKey = CScript() << 0x0 << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1368588225;
        genesis.nBits    = 0x1e0ffff0;
        genesis.nNonce   = 489173;

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0xbbd01e417e370842498a91038fd40da95f4a6166a231a3bed3c4671207bd8296"));
        assert(genesis.hashMerkleRoot == uint256("0x544583aec6ed7f7f045be86c3de9bd9043aca5968e30c82a276e76154cf34ef9"));

        vFixedSeeds.clear();
        vSeeds.clear();
/* //no dns seeds known for DBL
        vSeeds.push_back(CDNSSeedData("doubloonstools.com", "dnsseed.doubloonstools.com"));
        vSeeds.push_back(CDNSSeedData("doubloonspool.org", "dnsseed.doubloonspool.org"));
        vSeeds.push_back(CDNSSeedData("xurious.com", "dnsseed.ltc.xurious.com"));
        vSeeds.push_back(CDNSSeedData("koin-project.com", "dnsseed.koin-project.com"));
        vSeeds.push_back(CDNSSeedData("weminemnc.com", "dnsseed.weminemnc.com"));
*/
        base58Prefixes[PUBKEY_ADDRESS] = list_of(24);// Doubloons addresses start with D
        base58Prefixes[SCRIPT_ADDRESS] = list_of(5);
        base58Prefixes[SECRET_KEY] =     list_of(176);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x88)(0xB2)(0x1E);
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x88)(0xAD)(0xE4);

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        fRequireRPCPassword = true;
        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = false;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fSkipProofOfWorkCheck = false;
        fTestnetToBeDeprecatedFieldRPC = false;

        // Doubloons: Mainnet v2 enforced as of block 710k
        nEnforceV2AfterHeight = 710000;
    }

    const Checkpoints::CCheckpointData& Checkpoints() const 
    {
        return data;
    }
};
static CMainParams mainParams;

/**
 * Testnet (v3)
 */
class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        networkID = CBaseChainParams::TESTNET;
        strNetworkID = "test";
        pchMessageStart[0] = 0xfb;
        pchMessageStart[1] = 0xc0;
        pchMessageStart[2] = 0xb8;
        pchMessageStart[3] = 0xdb;
        vAlertPubKey = ParseHex("04302390343f91cc401d56d68b123028bf52e5fca1939df127f63c6467cdf9c8e2c14b61104cf817d0b780da337893ecc4aaff1309e536162dabbdb45200ca2b0a");
        nDefaultPort = 11336;
        nEnforceBlockUpgradeMajority = 51;
        nRejectBlockOutdatedMajority = 75;
        nToCheckBlockUpgradeMajority = 100;
        nMinerThreads = 0;
        nTargetTimespan = 0.5 * 24 * 60 * 60; // 0.5 days
        nTargetSpacing =  60; // 1 minute

        //! Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime = 1368588210;
        genesis.nNonce = 1147749;
        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0xa97b153a38b9d7879a75bd9cdf2bff1f4fc3cb156eaea52528b32927d9436836"));

        vFixedSeeds.clear();
        vSeeds.clear();
/* //no testned seeds known for DBL
        vSeeds.push_back(CDNSSeedData("doubloonstools.com", "testnet-seed.doubloonstools.com"));
        vSeeds.push_back(CDNSSeedData("xurious.com", "testnet-seed.ltc.xurious.com"));
        vSeeds.push_back(CDNSSeedData("wemine-testnet.com", "dnsseed.wemine-testnet.com"));
*/
        base58Prefixes[PUBKEY_ADDRESS] = list_of(111);
        base58Prefixes[SCRIPT_ADDRESS] = list_of(196);
        base58Prefixes[SECRET_KEY]     = list_of(239);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x35)(0x87)(0xCF);
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x35)(0x83)(0x94);

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        fRequireRPCPassword = true;
        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = false;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = true;

        // Doubloons: Testnet v2 enforced as of block 400k
        nEnforceV2AfterHeight = 400000;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const 
    {
        return dataTestnet;
    }
};
static CTestNetParams testNetParams;

/**
 * Regression test
 */
class CRegTestParams : public CTestNetParams {
public:
    CRegTestParams() {
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";
        pchMessageStart[0] = 0xfa;
        pchMessageStart[1] = 0xbf;
        pchMessageStart[2] = 0xb5;
        pchMessageStart[3] = 0xda;
        nSubsidyHalvingInterval = 150;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 1;
        nTargetTimespan = 3.5 * 24 * 60 * 60; // 3.5 days
        nTargetSpacing = 2.5 * 60; // 2.5 minutes
        bnProofOfWorkLimit = ~uint256(0) >> 1;
        genesis.nTime = 1296688602;
        genesis.nBits = 0x207fffff;
        genesis.nNonce = 0;
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 19444;
//WTF?        assert(hashGenesisBlock == uint256("0x530827f38f93b43ed12af0b3ad25a288dc02ed74d6d7857862df51fc56c416f9"));

        vFixedSeeds.clear(); //! Regtest mode doesn't have any fixed seeds.
        vSeeds.clear();  //! Regtest mode doesn't have any DNS seeds.

        fRequireRPCPassword = false;
        fMiningRequiresPeers = false;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fTestnetToBeDeprecatedFieldRPC = false;

        // Doubloons: v2 enforced using Bitcoin's supermajority rule
        nEnforceV2AfterHeight = -1;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const 
    {
        return dataRegtest;
    }
};
static CRegTestParams regTestParams;

/**
 * Unit test
 */
class CUnitTestParams : public CMainParams, public CModifiableParams {
public:
    CUnitTestParams() {
        networkID = CBaseChainParams::UNITTEST;
        strNetworkID = "unittest";
        nDefaultPort = 18445;
        vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
        vSeeds.clear();  //! Unit test mode doesn't have any DNS seeds.

        fRequireRPCPassword = false;
        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fAllowMinDifficultyBlocks = false;
        fMineBlocksOnDemand = true;

        // Doubloons: v2 enforced using Bitcoin's supermajority rule
        nEnforceV2AfterHeight = -1;
    }

    const Checkpoints::CCheckpointData& Checkpoints() const 
    {
        // UnitTest share the same checkpoints as MAIN
        return data;
    }

    //! Published setters to allow changing values in unit test cases
    virtual void setSubsidyHalvingInterval(int anSubsidyHalvingInterval)  { nSubsidyHalvingInterval=anSubsidyHalvingInterval; }
    virtual void setEnforceBlockUpgradeMajority(int anEnforceBlockUpgradeMajority)  { nEnforceBlockUpgradeMajority=anEnforceBlockUpgradeMajority; }
    virtual void setRejectBlockOutdatedMajority(int anRejectBlockOutdatedMajority)  { nRejectBlockOutdatedMajority=anRejectBlockOutdatedMajority; }
    virtual void setToCheckBlockUpgradeMajority(int anToCheckBlockUpgradeMajority)  { nToCheckBlockUpgradeMajority=anToCheckBlockUpgradeMajority; }
    virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks)  { fDefaultConsistencyChecks=afDefaultConsistencyChecks; }
    virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) {  fAllowMinDifficultyBlocks=afAllowMinDifficultyBlocks; }
    virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }
};
static CUnitTestParams unitTestParams;


static CChainParams *pCurrentParams = 0;

CModifiableParams *ModifiableParams()
{
   assert(pCurrentParams);
   assert(pCurrentParams==&unitTestParams);
   return (CModifiableParams*)&unitTestParams;
}

const CChainParams &Params() {
    assert(pCurrentParams);
    return *pCurrentParams;
}

CChainParams &Params(CBaseChainParams::Network network) {
    switch (network) {
        case CBaseChainParams::MAIN:
            return mainParams;
        case CBaseChainParams::TESTNET:
            return testNetParams;
        case CBaseChainParams::REGTEST:
            return regTestParams;
        case CBaseChainParams::UNITTEST:
            return unitTestParams;
        default:
            assert(false && "Unimplemented network");
            return mainParams;
    }
}

void SelectParams(CBaseChainParams::Network network) {
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}

bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;

    SelectParams(network);
    return true;
}
