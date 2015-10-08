/**
 * Definition of Interval:
 * class Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> ivec;
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });
        for (int i = 0; i < intervals.size(); ++i) {
            if (i == 0) {
                ivec.push_back(intervals[i]);
            } else if (intervals[i].end <= ivec[ivec.size() - 1].end) {
                continue;
            } else if (intervals[i].start <= ivec[ivec.size() - 1].end) {
                ivec[ivec.size() - 1].end = intervals[i].end;
            } else {
                ivec.push_back(intervals[i]);
            }
        }
        return ivec;
    }
};
