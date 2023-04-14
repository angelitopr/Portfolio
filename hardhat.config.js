require("@nomicfoundation/hardhat-toolbox");

require("@nomicfoundation/hardhat-toolbox");

// This is a sample Hardhat task. To learn how to create your own go to
// https://hardhat.org/guides/create-task.html
task("accounts", "Prints the list of accounts", async (taskArgs, hre) => {
    const accounts = await hre.ethers.getSigners();

    for (const account of accounts) {
        console.log(account.address);
    }
});

// You need to export an object to set up your config
// Go to https://hardhat.org/config/ to learn more

/**
 * @type import('hardhat/config').HardhatUserConfig
 */
module.exports = {
    solidity: "0.8.17",
    networks: {
      goerli: {
        url: "https://wiser-proud-county.ethereum-goerli.discover.quiknode.pro/eceb8ecaaf584ccb9470cb93e41e3210844fd38b/",
        accounts: ["4ccebfc06cf063dd7acfd206f0330734370e3f683baecf047d76d7201b5cd146"]
      },
    },
};

