commit 267f9bdd53a37d1cbee760d5af07880198e1beef
Author: Tommi <tommi@webrtc.org>
Date:   2023-12-21T14:08:26+01:00

    Update LegacyStatsCollector to conform with Wc++11-narrowing
    
    Bug: none
    Change-Id: Ida6a1af5c324473a55ea4f3b143862ea016ff50a
    Reviewed-on: https://webrtc-review.googlesource.com/c/src/+/332240
    Commit-Queue: Tomas Gunnarsson <tommi@webrtc.org>
    Reviewed-by: Harald Alvestrand <hta@webrtc.org>
    Auto-Submit: Tomas Gunnarsson <tommi@webrtc.org>
    Reviewed-by: Alexander Kornienko <alexfh@google.com>
    Reviewed-by: Henrik Boström <hbos@webrtc.org>
    Cr-Commit-Position: refs/heads/main@{#41432}

--- src/3rdparty/chromium/third_party/webrtc/pc/legacy_stats_collector.cc.orig	2023-11-20 16:08:07 UTC
+++ src/3rdparty/chromium/third_party/webrtc/pc/legacy_stats_collector.cc
@@ -189,9 +189,10 @@ void ExtractStats(const cricket::VoiceReceiverInfo& in
       {StatsReport::kStatsValueNameAccelerateRate, info.accelerate_rate},
       {StatsReport::kStatsValueNamePreemptiveExpandRate,
        info.preemptive_expand_rate},
-      {StatsReport::kStatsValueNameTotalAudioEnergy, info.total_output_energy},
+      {StatsReport::kStatsValueNameTotalAudioEnergy,
+       static_cast<float>(info.total_output_energy)},
       {StatsReport::kStatsValueNameTotalSamplesDuration,
-       info.total_output_duration}};
+       static_cast<float>(info.total_output_duration)}};
 
   const IntForAdd ints[] = {
       {StatsReport::kStatsValueNameCurrentDelayMs, info.delay_estimate_ms},
@@ -245,9 +246,10 @@ void ExtractStats(const cricket::VoiceSenderInfo& info
   SetAudioProcessingStats(report, info.apm_statistics);
 
   const FloatForAdd floats[] = {
-      {StatsReport::kStatsValueNameTotalAudioEnergy, info.total_input_energy},
+      {StatsReport::kStatsValueNameTotalAudioEnergy,
+       static_cast<float>(info.total_input_energy)},
       {StatsReport::kStatsValueNameTotalSamplesDuration,
-       info.total_input_duration}};
+       static_cast<float>(info.total_input_duration)}};
 
   RTC_DCHECK_GE(info.audio_level, 0);
   const IntForAdd ints[] = {
@@ -341,7 +343,8 @@ void ExtractStats(const cricket::VideoReceiverInfo& in
       {StatsReport::kStatsValueNamePlisSent, info.plis_sent},
       {StatsReport::kStatsValueNameRenderDelayMs, info.render_delay_ms},
       {StatsReport::kStatsValueNameTargetDelayMs, info.target_delay_ms},
-      {StatsReport::kStatsValueNameFramesDecoded, info.frames_decoded},
+      {StatsReport::kStatsValueNameFramesDecoded,
+       static_cast<int>(info.frames_decoded)},
   };
 
   for (const auto& i : ints)
@@ -385,15 +388,19 @@ void ExtractStats(const cricket::VideoSenderInfo& info
        info.encode_usage_percent},
       {StatsReport::kStatsValueNameFirsReceived, info.firs_rcvd},
       {StatsReport::kStatsValueNameFrameHeightSent, info.send_frame_height},
-      {StatsReport::kStatsValueNameFrameRateInput, round(info.framerate_input)},
+      {StatsReport::kStatsValueNameFrameRateInput,
+       static_cast<int>(round(info.framerate_input))},
       {StatsReport::kStatsValueNameFrameRateSent, info.framerate_sent},
       {StatsReport::kStatsValueNameFrameWidthSent, info.send_frame_width},
-      {StatsReport::kStatsValueNameNacksReceived, info.nacks_rcvd},
+      {StatsReport::kStatsValueNameNacksReceived,
+       static_cast<int>(info.nacks_rcvd)},
       {StatsReport::kStatsValueNamePacketsLost, info.packets_lost},
       {StatsReport::kStatsValueNamePacketsSent, info.packets_sent},
       {StatsReport::kStatsValueNamePlisReceived, info.plis_rcvd},
-      {StatsReport::kStatsValueNameFramesEncoded, info.frames_encoded},
-      {StatsReport::kStatsValueNameHugeFramesSent, info.huge_frames_sent},
+      {StatsReport::kStatsValueNameFramesEncoded,
+       static_cast<int>(info.frames_encoded)},
+      {StatsReport::kStatsValueNameHugeFramesSent,
+       static_cast<int>(info.huge_frames_sent)},
   };
 
   for (const auto& i : ints)
@@ -782,19 +789,25 @@ StatsReport* LegacyStatsCollector::AddConnectionInfoRe
                 AddCandidateReport(remote_candidate_stats, false)->id());
 
   const Int64ForAdd int64s[] = {
-      {StatsReport::kStatsValueNameBytesReceived, info.recv_total_bytes},
-      {StatsReport::kStatsValueNameBytesSent, info.sent_total_bytes},
-      {StatsReport::kStatsValueNamePacketsSent, info.sent_total_packets},
-      {StatsReport::kStatsValueNameRtt, info.rtt},
+      {StatsReport::kStatsValueNameBytesReceived,
+       static_cast<int64_t>(info.recv_total_bytes)},
+      {StatsReport::kStatsValueNameBytesSent,
+       static_cast<int64_t>(info.sent_total_bytes)},
+      {StatsReport::kStatsValueNamePacketsSent,
+       static_cast<int64_t>(info.sent_total_packets)},
+      {StatsReport::kStatsValueNameRtt, static_cast<int64_t>(info.rtt)},
       {StatsReport::kStatsValueNameSendPacketsDiscarded,
-       info.sent_discarded_packets},
+       static_cast<int64_t>(info.sent_discarded_packets)},
       {StatsReport::kStatsValueNameSentPingRequestsTotal,
-       info.sent_ping_requests_total},
+       static_cast<int64_t>(info.sent_ping_requests_total)},
       {StatsReport::kStatsValueNameSentPingRequestsBeforeFirstResponse,
-       info.sent_ping_requests_before_first_response},
-      {StatsReport::kStatsValueNameSentPingResponses, info.sent_ping_responses},
-      {StatsReport::kStatsValueNameRecvPingRequests, info.recv_ping_requests},
-      {StatsReport::kStatsValueNameRecvPingResponses, info.recv_ping_responses},
+       static_cast<int64_t>(info.sent_ping_requests_before_first_response)},
+      {StatsReport::kStatsValueNameSentPingResponses,
+       static_cast<int64_t>(info.sent_ping_responses)},
+      {StatsReport::kStatsValueNameRecvPingRequests,
+       static_cast<int64_t>(info.recv_ping_requests)},
+      {StatsReport::kStatsValueNameRecvPingResponses,
+       static_cast<int64_t>(info.recv_ping_responses)},
   };
   for (const auto& i : int64s)
     report->AddInt64(i.name, i.value);
