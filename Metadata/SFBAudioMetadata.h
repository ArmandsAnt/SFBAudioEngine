/*
 * Copyright (c) 2006 - 2020 Stephen F. Booth <me@sbooth.org>
 * See https://github.com/sbooth/SFBAudioEngine/blob/master/LICENSE.txt for license information
 */

#import <Foundation/Foundation.h>

#import "SFBAttachedPicture.h"

NS_ASSUME_NONNULL_BEGIN

/// Metadata kind bitmask values used in copyMetadataOfKind:from: and removeMetadataOfKind:
typedef NS_OPTIONS(NSUInteger, SFBAudioMetadataKind) {
	SFBAudioMetadataKindBasic			= (1u << 0),	///< Basic metadata
	SFBAudioMetadataKindSorting			= (1u << 1),	///< Sorting metadata
	SFBAudioMetadataKindGrouping		= (1u << 2),	///< Grouping metadata
	SFBAudioMetadataKindAdditional		= (1u << 3),	///< Additional metadata
	SFBAudioMetadataKindReplayGain		= (1u << 4)		///< Replay gain metadata
} NS_SWIFT_NAME(AudioMetadata.Kind);

typedef NSString * SFBAudioMetadataKey NS_TYPED_ENUM NS_SWIFT_NAME(AudioMetadata.Key);

// Basic metadata dictionary keys
extern SFBAudioMetadataKey const SFBAudioMetadataKeyTitle;							///< Title (\c NSString)
extern SFBAudioMetadataKey const SFBAudioMetadataKeyAlbumTitle;						///< Album title (\c NSString)
extern SFBAudioMetadataKey const SFBAudioMetadataKeyArtist;							///< Artist (\c NSString)
extern SFBAudioMetadataKey const SFBAudioMetadataKeyAlbumArtist;					///< Album artist (\c NSString)
extern SFBAudioMetadataKey const SFBAudioMetadataKeyGenre;							///< Genre (\c NSString)
extern SFBAudioMetadataKey const SFBAudioMetadataKeyComposer;						///< Composer (\c NSString)
extern SFBAudioMetadataKey const SFBAudioMetadataKeyReleaseDate;					///< Release date (\c NSString)
extern SFBAudioMetadataKey const SFBAudioMetadataKeyCompilation;					///< Compilation flag (\c NSNumber)
extern SFBAudioMetadataKey const SFBAudioMetadataKeyTrackNumber;					///< Track number (\c NSNumber)
extern SFBAudioMetadataKey const SFBAudioMetadataKeyTrackTotal;						///< Track total (\c NSNumber)
extern SFBAudioMetadataKey const SFBAudioMetadataKeyDiscNumber;						///< Disc number (\c NSNumber)
extern SFBAudioMetadataKey const SFBAudioMetadataKeyDiscTotal;						///< Disc total (\c NSNumber)
extern SFBAudioMetadataKey const SFBAudioMetadataKeyLyrics;							///< Lyrics (\c NSString)
extern SFBAudioMetadataKey const SFBAudioMetadataKeyBPM;							///< Beats per minute (BPM) (\c NSNumber)
extern SFBAudioMetadataKey const SFBAudioMetadataKeyRating;							///< Rating (\c NSNumber)
extern SFBAudioMetadataKey const SFBAudioMetadataKeyComment;						///< Comment (\c NSString)
extern SFBAudioMetadataKey const SFBAudioMetadataKeyISRC;							///< International Standard Recording Code (ISRC) (\c NSString)
extern SFBAudioMetadataKey const SFBAudioMetadataKeyMCN;							///< Media Catalog Number (MCN) (\c NSString)
extern SFBAudioMetadataKey const SFBAudioMetadataKeyMusicBrainzReleaseID;			///< MusicBrainz release ID (\c NSString)
extern SFBAudioMetadataKey const SFBAudioMetadataKeyMusicBrainzRecordingID;			///< MusicBrainz recording ID (\c NSString)

// Sorting dictionary keys
extern SFBAudioMetadataKey const SFBAudioMetadataKeyTitleSortOrder;					///< Title sort order (\c NSString)
extern SFBAudioMetadataKey const SFBAudioMetadataKeyAlbumTitleSortOrder;			///< Album title sort order (\c NSString)
extern SFBAudioMetadataKey const SFBAudioMetadataKeyArtistSortOrder;				///< Artist sort order (\c NSString)
extern SFBAudioMetadataKey const SFBAudioMetadataKeyAlbumArtistSortOrder;			///< Album artist sort order (\c NSString)
extern SFBAudioMetadataKey const SFBAudioMetadataKeyComposerSortOrder;				///< Composer sort order (\c NSString)
extern SFBAudioMetadataKey const SFBAudioMetadataKeyGenreSortOrder;					///< Genre sort order (\c NSString)

// Grouping dictionary keys
extern SFBAudioMetadataKey const SFBAudioMetadataKeyGrouping;						///< Grouping (\c NSString)

// Additional metadata dictionary keys
extern SFBAudioMetadataKey const SFBAudioMetadataKeyAdditionalMetadata;				///< Additional metadata (\c NSDictionary)

// Replay gain dictionary keys
extern SFBAudioMetadataKey const SFBAudioMetadataKeyReplayGainReferenceLoudness;	///< Replay gain reference loudness (\c NSNumber)
extern SFBAudioMetadataKey const SFBAudioMetadataKeyReplayGainTrackGain;			///< Replay gain track gain (\c NSNumber)
extern SFBAudioMetadataKey const SFBAudioMetadataKeyReplayGainTrackPeak;			///< Replay gain track peak (\c NSNumber)
extern SFBAudioMetadataKey const SFBAudioMetadataKeyReplayGainAlbumGain;			///< Replay gain album gain (\c NSNumber)
extern SFBAudioMetadataKey const SFBAudioMetadataKeyReplayGainAlbumPeak;			///< Replay gain album peak (\c NSNumber)

// Attached Picture dictionary keys
extern SFBAudioMetadataKey const SFBAudioMetadataKeyAttachedPictures;				///< Attached pictures (\c NSArray of \c NSDictionary)

/// Class supporting commonly-used audio metadata and attached pictures
NS_SWIFT_NAME(AudioMetadata) @interface SFBAudioMetadata : NSObject <NSCopying>

/// Returns an initialized empty \c SFBAudioMetadata object
- (instancetype)init NS_DESIGNATED_INITIALIZER;

/// Returns an initialized \c SFBAudioMetadata object populated with values from \c dictionaryRepresentation
/// @param dictionaryRepresentation A dictionary containing the desired values
- (instancetype)initWithDictionaryRepresentation:(NSDictionary<SFBAudioMetadataKey, id> *)dictionaryRepresentation;

#pragma mark - Basic Metadata

/// The title
@property (nonatomic, nullable) NSString *title;

/// The album title
@property (nonatomic, nullable) NSString *albumTitle;

/// The artist
@property (nonatomic, nullable) NSString *artist;

/// The album artist
@property (nonatomic, nullable) NSString *albumArtist;

/// The genre
@property (nonatomic, nullable) NSString *genre;

/// The composer
@property (nonatomic, nullable) NSString *composer;

/// The release date
@property (nonatomic, nullable) NSString *releaseDate;

/// The compilation flag
@property (nonatomic, nullable) NSNumber *compilation;

/// The track number
@property (nonatomic, nullable) NSNumber *trackNumber;

/// The track total
@property (nonatomic, nullable) NSNumber *trackTotal;

/// The disc number
@property (nonatomic, nullable) NSNumber *discNumber;

/// The disc total
@property (nonatomic, nullable) NSNumber *discTotal;

/// The lyrics
@property (nonatomic, nullable) NSString *lyrics;

/// The Beats per minute (BPM)
@property (nonatomic, nullable) NSNumber *bpm;

/// The rating
@property (nonatomic, nullable) NSNumber *rating;

/// The comment
@property (nonatomic, nullable) NSString *comment;

/// The Media Catalog Number (MCN)
@property (nonatomic, nullable) NSString *mcn;

/// The International Standard Recording Code (ISRC)
@property (nonatomic, nullable) NSString *isrc;

/// The MusicBrainz release ID
@property (nonatomic, nullable) NSString *musicBrainzReleaseID;

/// The MusicBrainz recording ID
@property (nonatomic, nullable) NSString *musicBrainzRecordingID;

#pragma mark - Sorting Metadata

/// The title sort order
@property (nonatomic, nullable) NSString *titleSortOrder;

/// The album title sort order
@property (nonatomic, nullable) NSString *albumTitleSortOrder;

/// The artist sort order
@property (nonatomic, nullable) NSString *artistSortOrder;

/// The album artist sort order
@property (nonatomic, nullable) NSString *albumArtistSortOrder;

/// The composer sort order
@property (nonatomic, nullable) NSString *composerSortOrder;

/// The genre sort order
@property (nonatomic, nullable) NSString *genreSortOrder;

#pragma mark - Grouping Metadata

/// The grouping
@property (nonatomic, nullable) NSString *grouping;

#pragma mark - Additional Metadata

/// The additional metadata
@property (nonatomic, nullable) NSDictionary *additionalMetadata;

#pragma mark - ReplayGain Metadata

/// The replay gain reference loudness
@property (nonatomic, nullable) NSNumber *replayGainReferenceLoudness;

/// The replay gain track gain
@property (nonatomic, nullable) NSNumber *replayGainTrackGain;

/// The replay gain track peak
@property (nonatomic, nullable) NSNumber *replayGainTrackPeak;

/// The replay gain album gain
@property (nonatomic, nullable) NSNumber *replayGainAlbumGain;

/// The replay gain album peak
@property (nonatomic, nullable) NSNumber *replayGainAlbumPeak;

#pragma mark - Metadata Utilities

/// Copies all metadata from \c metadata
/// @note Does not copy album artwork
/// @param metadata A \c Metadata object containing the metadata to copy
/// @see -copyMetadataOfKind:from:
/// @see -copyAttachedPictures:
- (void)copyMetadataFrom:(SFBAudioMetadata *)metadata NS_SWIFT_NAME(copyMetadata(from:));

/// Copies the values contained in the specified metadata kinds from \c metadata
/// @note Does not copy album artwork
/// @param metadata A \c Metadata object containing the metadata to copy
/// @param kind A bitmask specifying the kinds of metadata to copy
/// @see -copyMetadataFrom:
/// @see -copyAttachedPictures
- (void)copyMetadataOfKind:(SFBAudioMetadataKind)kind from:(SFBAudioMetadata *)metadata NS_SWIFT_NAME(copyMetadata(ofKind:from:));

/// Sets the values contained in specified metadata kinds to \c nullptr
/// @param kind A bitmask specifying the kinds of metadata to remove
/// @see -removeAllMetadata
/// @see -removeAllAttachedPictures
- (void)removeMetadataOfKind:(SFBAudioMetadataKind)kind NS_SWIFT_NAME(removeMetadata(ofKind:));

/// Sets all metadata to \c nullptr
/// @note Leaves album art intact
/// @see -removeMetadataOfKind:
/// @see -removeAllAttachedPictures
- (void)removeAllMetadata;

#pragma mark - Attached Pictures

/// Get all attached pictures
@property (nonatomic, readonly) NSSet<SFBAttachedPicture *> *attachedPictures;

#pragma mark - Attached Picture Utilities

/// Copies album artwork from \c metadata
/// @note This clears existing album artwork
/// @note Does not copy metadata
/// @param metadata A \c SFBAudioMetadata object containing the artwork to copy
/// @see -copyMetadataFrom:
- (void)copyAttachedPicturesFrom:(SFBAudioMetadata *)metadata NS_SWIFT_NAME(copyAttachedPicturesFrom(_:));

/// Get all attached pictures of the specified type
- (NSArray<SFBAttachedPicture *> *)attachedPicturesOfType:(SFBAttachedPictureType)type NS_SWIFT_NAME(attachedPictures(ofType:));

/// Attach a picture
- (void)attachPicture:(SFBAttachedPicture *)picture NS_SWIFT_NAME(attachPicture(_:));

/// Remove an attached picture
- (void)removeAttachedPicture:(SFBAttachedPicture *)picture NS_SWIFT_NAME(removeAttachedPicture(_:));

/// Remove all attached pictures of the specified type
- (void)removeAttachedPicturesOfType:(SFBAttachedPictureType)type NS_SWIFT_NAME(removeAttachedPicturesOfType(_:));

/// Remove all attached pictures
- (void)removeAllAttachedPictures;

#pragma mark - External Representation

/// Copy the values contained in this object to a dictionary
/// @return A dictionary containing this object's metadata and attached pictures
@property (nonatomic, readonly) NSDictionary<SFBAudioMetadataKey, id> *dictionaryRepresentation;

/// Sets the metadata and attached pictures contained in this object from a dictionary
/// @param dictionary A dictionary containing the desired values
- (void)setFromDictionaryRepresentation:(NSDictionary<SFBAudioMetadataKey, id> *)dictionary NS_SWIFT_NAME(setFrom(_:));

@end

NS_ASSUME_NONNULL_END