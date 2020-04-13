#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include<list>
#include <vector>

using namespace std;

class Twitter {
private:
	struct TNode {
		unordered_set<int> fllower; // 关注人列表
		list<int> twitters; // 自己的推文列表
	};
	int Time = 0, MaxSize = 10; // 推文时间，推文列表长度
	unordered_map<int, int> tweetTime; // 推文时间
	unordered_map<int, TNode> users; // 用户信息
public:
	/** Initialize your data structure here. */
	Twitter() {
		
	}
	void userCreat(int userId){
		users[userId].fllower.clear();
		users[userId].twitters.clear();
	}
	/** Compose a new tweet. */
	void postTweet(int userId, int tweetId) {
		if (users.find(userId) == users.end())
			userCreat(userId);
		if (users[userId].twitters.size() == MaxSize){
			users[userId].twitters.pop_back();
		}
		users[userId].twitters.push_front(tweetId);
		tweetTime[tweetId] = ++Time;
	}

	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	vector<int> getNewsFeed(int userId) {
		vector<int> ret;
		for (auto e : users[userId].twitters){ // 先放入自己的推文
			ret.push_back(e);
		}
		for (auto followeeId : users[userId].fllower) {
			if (followeeId == userId) // 可能出现自己关注自己的情况
				continue;
			vector<int> res;
			res.clear();
			auto it = users[followeeId].twitters.begin();
			size_t i = 0;
			// 线性归并
			while (i < ret.size() && it != users[followeeId].twitters.end()) {
				if (tweetTime[(*it)] > tweetTime[ret[i]]) {
					res.emplace_back(*it);
					++it;
				}
				else {
					res.emplace_back(ret[i]);
					++i;
				}
				// 已经找到这两个链表合起来后最近的 recentMax 条推文
				if ((int)res.size() == MaxSize) 
					break;
			}
			for (; i < (int)ret.size() && (int)res.size() < MaxSize; ++i) 
				res.emplace_back(ret[i]);
			for (; it != users[followeeId].twitters.end() && (int)res.size() < MaxSize; ++it)
				res.emplace_back(*it);
			ret.assign(res.begin(), res.end());
		}
		return ret;
	}

	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	void follow(int followerId, int followeeId) {
		if (users.find(followeeId) == users.end())
			userCreat(followeeId);
		if (users.find(followerId) == users.end())
			userCreat(followerId);

		users[followerId].fllower.insert(followeeId);
	}

	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void unfollow(int followerId, int followeeId) {
		users[followerId].fllower.erase(followeeId);
	}
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

int main()
{

	system("pause");
	return 0;
}