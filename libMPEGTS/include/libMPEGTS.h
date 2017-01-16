/*!
 @header    libMPEGTS
 @author    Marcus Johnson aka BumbleBritches57
 @copyright 2017, released under the BSD 3 clause license
 @version   0.0
 @brief     This library contains a muxer and demuxer for MPEG2-TS aka H.222 streams
 */

#include "/usr/local/Packages/BitIO/include/BitIO.h"
#include "libMPEGTSTables.h"

#pragma once

#ifdef __cplusplus
extern "C" {
#endif
    
    extern enum MPEGTSConstants {
        MPEGTSMaxPrivateData     = 256,
        PESPacketStartCodePrefix = 0x000001,
    } MPEGTSConstants;
    
    typedef struct PacketizedElementaryStream {
        int32_t  PacketStartCodePrefix:24;     // packet_start_code_prefix
        uint8_t  StreamID;                     // stream_id
        uint16_t PESPacketSize;                // PES_packet_length
        uint8_t  PESScramblingControl;         // PES_scrambling_control
        bool     PESPriority:1;                // PES_priority
        bool     AlignmentIndicator:1;         // data_alignment_indicator
        bool     CopyrightIndicator:1;         // copyright
        bool     OriginalOrCopy:1;              // original_or_copy
        uint8_t  PTSDTSFlags:2;                 // PTS_DTS_flags
        bool     ESCRFlag:1;                    // ESCR_flag
        bool     ESRateFlag:1;                  // ES_rate_flag
        bool     DSMTrickModeFlag:1;            // DSM_trick_mode_flag
        bool     AdditionalCopyInfoFlag:1;      // additional_copy_info_flag
        bool     PESCRCFlag:1;                  // PES_CRC_flag
        bool     PESExtensionFlag:1;            // PES_extension_flag
        uint8_t  PESHeaderSize;                 // PES_header_data_length
        uint64_t PTS:33;                        // PTS
        uint64_t DTS:33;                        // DTS
        uint64_t ESCR:33;                       // ESCR
        uint32_t ESRate:22;                     // ES_rate
        uint8_t  TrickModeControl:3;            // trick_mode_control
        uint8_t  FieldID:2;                     // field_id
        bool     IntraSliceRefresh:1;           // intra_slice_refresh
        uint8_t  FrequencyTruncation:2;         // frequency_truncation
        uint8_t  RepetitionControl:5;           // rep_cntrl
        uint8_t  AdditionalCopyInfo:7;          // additional_copy_info
        uint16_t PreviousPESPacketCRC;          // previous_PES_packet_CRC
        bool     PESPrivateDataFlag:1;          // PES_private_data_flag
        bool     PackHeaderFieldFlag:1;         // pack_header_field_flag
        bool     ProgramPacketSeqCounterFlag:1; // program_packet_sequence_counter_flag
        bool     PSTDBufferFlag:1;              // P-STD_buffer_flag
        bool     PESExtensionFlag2:1;           // PES_extension_flag_2
        uint8_t  PackFieldSize;                 // pack_field_length
        uint8_t  ProgramPacketSeqCounter:7;     // program_packet_sequence_counter
        bool     MPEGVersionIdentifier:1;       // MPEG1_MPEG2_identifier
        uint8_t  OriginalStuffSize:6;           // original_stuff_length
        uint8_t  PSTDBufferScale:1;             // P-STD_buffer_scale
        uint16_t PSTDBufferSize:13;             // P-STD_buffer_size
        uint8_t  PESExtensionFieldSize:7;       // PES_extension_field_length
        bool     StreamIDExtensionFlag:1;       // stream_id_extension_flag
        uint8_t  StreamIDExtension:7;           // stream_id_extension
        bool     TREFFieldPresentFlag:1;        // tref_extension_flag
        uint32_t TREF;                          // TREF
    } PacketizedElementaryStream;
    
    typedef struct TransportStreamPacket {
        int8_t   SyncByte;                     // sync_byte
        bool     TransportErrorIndicator:1;    // transport_error_indicator
        bool     StartOfPayloadIndicator:1;    // payload_unit_start_indicator
        bool     TransportPriorityIndicator:1; // transport_priority
        uint16_t PID:13;                       // PID
        int8_t   TransportScramblingControl:2; // transport_scrambling_control
        int8_t   AdaptationFieldControl:2;     // adaptation_field_control
        uint8_t  ContinuityCounter:4;          // continuity_counter
    } TransportStreamPacket;
    
    typedef struct TSAdaptationField {
        uint8_t  AdaptationFieldSize;                 // adaptation_field_length
        bool     DiscontinuityIndicator:1;            // discontinuity_indicator
        bool     RandomAccessIndicator:1;             // random_access_indicator
        bool     ElementaryStreamPriorityIndicator:1; // elementary_stream_priority_indicator
        bool     PCRFlag:1;                           // PCR_flag
        bool     OPCRFlag:1;                          // OPCR_flag
        bool     SlicingPointFlag:1;                  // splicing_point_flag
        bool     TransportPrivateDataFlag:1;          // transport_private_data_flag
        bool     AdaptationFieldExtensionFlag:1;      // adaptation_field_extension_flag
        uint64_t ProgramClockReferenceBase:33;        // program_clock_reference_base
        uint16_t ProgramClockReferenceExtension:9;    // program_clock_reference_extension
        uint64_t OriginalProgramClockRefBase:33;      // original_program_clock_reference_base
        uint16_t OriginalProgramClockRefExt:9;        // original_program_clock_reference_extension
        int8_t   SpliceCountdown;                     // splice_countdown
        uint8_t  TransportPrivateDataSize;            // transport_private_data_length
        uint8_t  TransportPrivateData[MPEGTSMaxPrivateData];           // private_data_byte
        uint8_t  AdaptationFieldExtensionSize;        // adaptation_field_extension_length
        bool     LegalTimeWindowFlag:1;               // ltw_flag
        bool     PiecewiseRateFlag:1;                 // piecewise_rate_flag
        bool     SeamlessSpliceFlag:1;                // seamless_splice_flag
        bool     LegalTimeWindowValidFlag:1;          // ltw_valid_flag
        uint16_t LegalTimeWindowOffset:15;            // ltw_offset
        uint32_t PiecewiseRate:22;                    // piecewise_rate
        uint8_t  SpliceType:4;                        // Splice_type
        uint64_t DecodeTimeStampNextAU:33;            // DTS_next_AU
    } TSAdaptationField;
    
    typedef struct MPEGTransportStream {
        TransportStreamPacket      *Packet;
        TSAdaptationField          *Adaptation;
        PacketizedElementaryStream *PES;
    } MPEGTransportStream;
    
#ifdef __cplusplus
}
#endif
