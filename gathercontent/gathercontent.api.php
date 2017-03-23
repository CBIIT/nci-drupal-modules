<?php

/**
 * @file
 * Hooks provided by the GatherContent module.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Alter node or its fields before it's saved.
 *
 * You can change all node properties and perform various operations with them
 * before the node is saved in Drupal. Node doesn't have node ID while calling
 * this hook. Menu items and meta tags aren't saved/created while calling this hook.
 * For operations requiring node ID @see hook_gathercontent_post_node_save_alter().
 *
 * @param object $entity
 *   Entity metadata wrapper of node.
 * @param $source_values
 *   Source fields representing object in GatherContent.
 * @param array $files
 *   Array of files fetched from GatherContent.
 */
function hook_gathercontent_pre_node_save_alter(&$entity, &$source_values, array &$files) {
}

/**
 * Alter node or its fields after it's saved.
 *
 * You can change all node properties and perform various operations with them
 * after the node is saved in Drupal. Node have node ID while calling
 * this hook. Menu items and meta tags are already saved/created while calling
 * this hook.
 *
 * @param object $entity
 *   Entity metadata wrapper of node.
 * @param $source_values
 *   Source fields representing object in GatherContent.
 * @param array $files
 *   Array of files fetched from GatherContent.
 */
function hook_gathercontent_post_node_save($entity, $source_values, array $files) {
}

/**
 * Alter configuration before it's uploaded to GatherContent.
 *
 * You can change configuration or node before it's uploaded to GatherContent.
 *
 * @param object $node
 *   Object of node.
 * @param $source_values
 *   Source fields representing object in GatherContent.
 */
function hook_gathercontent_pre_node_upload_alter(&$node, &$source_values) {
}

/**
 * Alter node after its configuration is uploaded to GatherContent.
 *
 * You can change all node properties and perform various operations with them
 * after the node is uploaded to GatherContent.
 *
 * @param object $node
 *   Object of node.
 * @param $source_values
 *   Source fields representing object in GatherContent.
 */
function hook_gathercontent_post_node_upload($node, $source_values) {
}

/**
 * Perform operations on all items which entered import or update.
 *
 * You can use this hook to create relations between nodes or creating various
 * statistics about imports and updates. You can fetch type of operation
 * from Operation entity.
 *
 * @param array $success
 *   Array of arrays with successfully imported nids and their gathercontent_id.
 * @param array $unsuccess
 *   Array of arrays with unsuccessfully imported nids and their gathercontent_id.
 * @param $operation_id
 *   ID of operation. You can fetch Operation entity or all OperationItem
 * entities related to Operation by this parameter.
 */
function hook_gathercontent_post_import(array $success, array $unsuccess, $operation_id) {
}

/**
 * Perform operations on all items which entered upload.
 *
 * You can use this hook to create relations between nodes or creating various
 * statistics about uploads. You can fetch type of operation
 * from Operation entity.
 *
 * @param array $success
 *   Array of arrays with successfully imported nids and their gathercontent_id.
 * @param array $unsuccess
 *   Array of arrays with unsuccessfully imported nids and their gathercontent_id.
 * @param $operation_id
 *   ID of operation. You can fetch Operation entity or all OperationItem
 * entities related to Operation by this parameter.
 */
function hook_gathercontent_post_upload(array $success, array $unsuccess, $operation_id) {
}

/**
 * @} End of "addtogroup hooks".
 */