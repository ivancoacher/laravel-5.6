<?php

class fs_context_condition_article_category extends context_condition_node {
  function condition_values() {
    $values = [];
    if (module_exists('taxonomy')) {
      $vocab_machine_names = $this->get_vocab_machine_names();
      foreach ($vocab_machine_names as $vocab_machine_name) {
        $vocab = taxonomy_vocabulary_machine_name_load($vocab_machine_name);
        if (isset($vocab->vid)) {
          $terms = taxonomy_get_tree($vocab->vid, 0, 1);
          if (!empty($terms)) {
            foreach ($terms as $term) {
              $values[$term->tid] = check_plain($term->name);
            }
          }
        }
      }
    }

    return $values;
  }

  function condition_form($context) {
    $form = parent::condition_form($context);
    $form['#type'] = 'select';
    $form['#size'] = 12;
    $form['#multiple'] = TRUE;
    $options = array();
    $vocab_machine_names = $this->get_vocab_machine_names();

    foreach ($vocab_machine_names as $vocab_machine_name) {
      $vocab = taxonomy_vocabulary_machine_name_load($vocab_machine_name);
      if (isset($vocab->vid)) {
        $tree = taxonomy_get_tree($vocab->vid, 0, 1);
        if ($tree && (count($tree) > 0)) {
          $options[$vocab->name] = array();
          foreach ($tree as $term) {
            $options[$vocab->name][$term->tid] = str_repeat('-', $term->depth) . $term->name;
          }
        }
      }
    }

    $form['#options'] = $options;

    return $form;
  }

  function execute($node, $op) {
    $tid_to_match = '';
    if($node->type == 'article') {
      $node_wrapper = entity_metadata_wrapper('node', $node);
      $field_article_category = $node_wrapper->field_article_category->value();

      if(!empty($field_article_category)) {
        foreach($field_article_category as $item) {
          if(is_object($item)) {
            $category = $item;
            break;
          }
        }
      }

      $term = taxonomy_term_load($category->tid);
      if(is_object($term)) {
        $parents = taxonomy_get_parents_all($term->tid);
        $parent = end($parents);
        $tid_to_match = $parent->tid;
      }
    }

    if($this->condition_used() && !empty($tid_to_match)) {
      foreach($this->get_contexts($tid_to_match) as $context) {
        $this->condition_met($context, $tid_to_match);
      }
    }
  }

  function get_vocab_machine_names() {
    return [
      'article_category_bj',
      'article_category_sh',
    ];
  }
}
