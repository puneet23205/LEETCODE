class Bank {
    vector<long long> bal;
public:
    Bank(vector<long long>& balance) {
        bal = balance;
    }
    
    bool isValid(int acc) {
        return acc >= 1 && acc <= bal.size();
    }

    bool transfer(int account1, int account2, long long money) {
        if (!isValid(account1) || !isValid(account2) || bal[account1 - 1] < money)
            return false;
        bal[account1 - 1] -= money;
        bal[account2 - 1] += money;
        return true;
    }

    bool deposit(int account, long long money) {
        if (!isValid(account)) return false;
        bal[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (!isValid(account) || bal[account - 1] < money) return false;
        bal[account - 1] -= money;
        return true;
    }
};
